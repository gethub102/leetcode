/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class Solution {
  public:
    int minCut(string s) {
        int length =  s.length();
        bool isPalindrome[length][length];
        int dp[length];
        for (int i = 0; i < length; i++) {
            dp[i] = length - 1 - i; // the worst case, cut every char
        }
        for (int i = length - 1; i >= 0; i--) {
            for (int j = i; j <= length - 1; j++) {
                if (i == j) {
                    isPalindrome[i][j] = true;
                } else if (i + 1 == j) {
                    isPalindrome[i][j] = s[i] == s[j];
                } else {
                    isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i + 1][j - 1];
                }
                if (isPalindrome[i][j]) {
                    if (j == length - 1) {
                        dp[i] = 0;
                    } else {
                        dp[i] = min(dp[i], dp[j + 1] + 1); // cut between j and j+1, comparison, update
                    }
                }
            }
        }
        return dp[0];
    }
};

// rewrite

class Solution {
  public:
    int minCut(string s) {
        bool isPalindrome[s.length()][s.length()];
        vector<int> dp(s.length() , 1);
        for (int i = 0; i < s.length(); i++) {
            dp[i] = s.length() - i - 1;
        }
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (i == j) {
                    isPalindrome[i][j] = true;
                } else if (j == i + 1) {
                    isPalindrome[i][j] = s[i] == s[j];
                } else {
                    isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
                }
                if (isPalindrome[i][j]) {
                    if (j == s.length() - 1) {
                        dp[i] = 0;
                    } else {
                        dp[i] = min(dp[i], 1 + dp[j + 1]);
                    }
                }
            }
        }
        return dp[0];
    }
};
