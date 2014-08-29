/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/
class Solution {
  public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> oneSolution;
        sort(candidates.begin(), candidates.end());
        combinationSumDFS(result, oneSolution, candidates, target);
        return result;
    }

    void combinationSumDFS(vector<vector<int>>& result, vector<int> oneSolution, vector<int>& candidates, int target) {
        if (target == 0 && !oneSolution.empty()) {
            result.push_back(oneSolution);
            return;
        }
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] <= target && (oneSolution.empty() || candidates[i] >= oneSolution.back())) {
                oneSolution.push_back(candidates[i]);
                combinationSumDFS(result, oneSolution, candidates, target - candidates[i]);
                oneSolution.pop_back();
            }
        }
    }
};

// rewrite

class Solution {
  public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        if (candidates.empty()) {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> singleSolution;
        combinationSumDFS(result, singleSolution, candidates, target);
        return result;
    }

    void combinationSumDFS(vector<vector<int> >& result, vector<int> singleSolution, vector<int> candidates, int target) {
        if (target == 0) {
            if (!singleSolution.empty()) {
                result.push_back(singleSolution);
            }
            return;
        }
        for (int i = 0; i < candidates.size(); i++) {
            if (candidates[i] <= target && (singleSolution.empty() || candidates[i] >= singleSolution.back())) {
                singleSolution.push_back(candidates[i]);
                combinationSumDFS(result, singleSolution, candidates, target - candidates[i]);
                singleSolution.pop_back();
            }
        }
    }
};
