class Solution {
  public:
    int trap(int A[], int n) {
        int result = 0;
        int i;
        int left[n];
        int right[n];
        int sub[n];
		// from left to right
        left[0] = A[0];
        for (i = 1; i < n; i++) {
            left[i] = max(left[i - 1], A[i]);
        }
		// from rigth to left
        right[n - 1] = A[n - 1];
        sub[n - 1] = min(left[n - 1], right[n - 1]);
        for (i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], A[i]);
            sub[i] = min(left[i], right[i]);
            result += (sub[i] - A[i]);
        }
        return result;
    }
};
