class Solution {
  public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> currentCombination;
        combineRecursion(result, currentCombination, 0, k, n);
        return result;
    }

    void combineRecursion(vector<vector<int> >& result, vector<int> currentCombination, int currentSize, int size, int n) {
        if (currentSize == size) {
            result.push_back(currentCombination);
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (currentCombination.empty() || i > currentCombination.back()) {
                currentCombination.push_back(i);
                combineRecursion(result, currentCombination, currentSize + 1, size, n);
                currentCombination.pop_back();
            }
        }
    }
};
