class Solution {
  public:
    int minCut(string s) {
        int length =  s.length();
        bool isPalindrome[length][length];
        int dp[length - 1];
        for (int i = 0; i < length; i++) {
            dp[i] = length - 1 - i; // the worst case, cut every char
        }
        for (int i = length - 1; i >= 0; i--) {
            for (int j = i; j <= length - 1; j++) {
                if (i == j) isPalindrome[i][j] = true;
                else if (i + 1 == j) isPalindrome[i][j] = s[i] == s[j];
                else isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i + 1][j - 1];
                if (isPalindrome[i][j]) {
                    if (j == length - 1) dp[i] = 0;
                    else dp[i] = min(dp[i], dp[j + 1] + 1); // cut between j and j+1, comparison, update
                }
            }
        }
        return dp[0];
    }
};
