class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& num, int target) {
        vector<vector<int> > results;
        vector<int> singleSolution;
        sort(num.begin(), num.end());
        combinationSum2Recursion(results, singleSolution, num, target);
        return results;
    }

    void combinationSum2Recursion(vector<vector<int> >& results, vector<int> singleSolution, vector<int>& num, int target) {
        if (target == 0) {
            results.push_back(singleSolution);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            if (singleSolution.empty() || (target - num[i] >= 0 && num[i] >= singleSolution.back())) {
                int tmp = num[i]; // difference
                singleSolution.push_back(tmp);
                num.erase(num.begin() + i); // difference
                combinationSum2Recursion(results, singleSolution, num, target - tmp);
                num.push_back(tmp); // difference
                sort(num.begin(), num.end()); //difference
                singleSolution.pop_back();
            }
        }
    }
};
