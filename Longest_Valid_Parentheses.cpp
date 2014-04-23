class Solution {
  public:
    int longestValidParentheses(string s) {

        if (s.length() < 2) return 0;
        int maxLen = 0;
        int dp[s.length()];
        // dp[i] means a
        dp[s.length() - 1] = 0; // or use memset(dp, 0, sizeof(dp));
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] == ')') {
                dp[i] = 0;
            } else {
                int j = i + dp[i + 1] + 1;
                if (j < s.length() && s[j] == ')') {
                    dp[i] = dp[i + 1] + 2;
                    if (j + 1 < s.length()) dp[i] += dp[j + 1];
                } else {
                    dp[i] = 0; // important!!!
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
