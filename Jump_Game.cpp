class Solution {
  public:
    bool canJump(int A[], int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; i++) {
            for (int j = i; j >= 0 ; j--) {
                if (dp[j] == true && A[j] >= i - j) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
/*
class Solution {
  public:
    bool canJump(int A[], int n) {
        int maxCover = 0;
        for (int start = 0; start <= maxCover && start < n; start++)         {
            maxCover = max(maxCover, A[start] + start);
            if (maxCover >= n - 1) return true;
        }
        return false;
    }
};
*/
