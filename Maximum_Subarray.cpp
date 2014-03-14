class Solution {
public:
    int maxSubArray(int A[], int n) {
        int max_so_far  = A[0], max_ending_here = A[0];
        for (int i = 1; i < n; i++) {
            if (max_ending_here < 0) {
                max_ending_here = A[i];
            } else {
                max_ending_here += A[i];
            }
            max_so_far = max(max_ending_here, max_so_far);
        }
        return max_so_far ;
    }
};