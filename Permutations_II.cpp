class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& num) {
        vector<vector<int> > result;
        vector<int> singleSolution;
        vector<bool>  visited(num.size(), false);
        sort(num.begin(), num.end());
        permuteUniqueRecursion(result, singleSolution, num, visited);
        return result;
    }

    void permuteUniqueRecursion(vector<vector<int> >& result, vector<int>& singleSolution, vector<int> num, vector<bool>& visited) {
        if (singleSolution.size() == num.size()) {
            result.push_back(singleSolution);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (visited[i] == false) {
                if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == false)continue;
                singleSolution.push_back(num[i]);
                visited[i] = true;
                permuteUniqueRecursion(result, singleSolution, num, visited);
                visited[i] = false;
                singleSolution.pop_back();
            }
        }
    }
};
