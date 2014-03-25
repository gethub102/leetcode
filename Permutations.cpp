class Solution {
  public:
    vector<vector<int> > permute(vector<int>& num) {
        vector<vector<int> > result;
        vector<int> currentPermutaions;
        permuteRecursion(result, currentPermutaions, num, 0, num.size());
        return result;
    }

    void permuteRecursion(vector<vector<int> >& result, vector<int> currentPermutaions, vector<int> num, int currentSize, int size) {
        if (currentSize == size) {
            result.push_back(currentPermutaions);
            return;
        }
        for (int i = 0; i < size; i++) {
            if (currentPermutaions.empty() ||
                    find(currentPermutaions.begin(), currentPermutaions.end(), num[i]) == currentPermutaions.end()) {
                currentPermutaions.push_back(num[i]);
                permuteRecursion(result, currentPermutaions, num, currentSize + 1, size);
                currentPermutaions.pop_back();
            }
        }

    }
};
