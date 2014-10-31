/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, â€¦ , ak) must be in non-descending order. (ie, a1 â‰¤ a2 â‰¤ â€¦ â‰¤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/
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
