class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> results;
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (A[i] == target && A[j] == target) {
                results.push_back(i);
                results.push_back(j);
                return results;
            } else if (A[i] < target) {
                i++;
            } else if (A[j] > target) {
                j--;
            }
        }
        results.push_back(-1);
        results.push_back(-1);
        return results;
    }
};