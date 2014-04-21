class Solution {
  public:
    int maxSubArray(int A[], int n) {
        int max_value = A[0];
        int tmp = A[0];
        for (int i = 1; i < n; i++) {
            if (tmp  < 0) {
                tmp  = A[i];
            } else {
                tmp += A[i];
            }
            max_value = max(max_value, tmp);
        }
        return max_value;
    }
};