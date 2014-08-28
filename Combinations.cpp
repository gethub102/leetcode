/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
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

// rewrite

class Solution {
  public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (k == 0 || k  > n) {
            return result;
        }
        vector<int> singleSolution;
        combineDFS(result, singleSolution, n, k);
        return result;
    }

    void combineDFS(vector<vector<int> >& result, vector<int> singleSolution, int n, int k) {
        if (singleSolution.size() == k) {
            result.push_back(singleSolution);
            return;
        }
        for (int i = 1; i <= n; i++) {
            if (singleSolution.empty() || i > singleSolution.back()) {
                singleSolution.push_back(i);
                combineDFS(result, singleSolution, n, k);
                singleSolution.pop_back();
            }
        }
    }
};
