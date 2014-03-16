class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > results;
        vector<int> singleSolution;
        sort(candidates.begin(), candidates.end());
        combinationSumRecusion(results, singleSolution, candidates, target);
        return results;
    }

    void combinationSumRecusion(vector<vector<int> >& results, vector<int> singleSolution, vector<int> candidates, int target) {
        if (target == 0) {
            results.push_back(singleSolution);
            return;
        }
        for (int i = 0; i < candidates.size(); i++) {
            if (singleSolution.empty() || (target - candidates[i] >= 0 && candidates[i] >= singleSolution.back())) {
                singleSolution.push_back(candidates[i]);
                combinationSumRecusion(results, singleSolution, candidates, target - candidates[i]);
                singleSolution.pop_back();
            }
        }
    }
};
