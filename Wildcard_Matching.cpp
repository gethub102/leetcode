/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/
class Solution {
  public:
    bool isMatch(const char* s, const char* p) {
        int n = strlen(s), m = strlen(p), i, j, chars = 0;
        for (i = 0; p[i] != '\0'; ++i) {
            if (p[i] != '*' && n < ++chars) {
                return false;
            }
        }
        vector<bool> dp(n + 2, false);
        for (i = m - 1, dp[n] = true; i >= 0; --i) {
            if (p[i] == '*') {
                while (i > 0 && p[i] == p[i - 1]) {
                    --i;   //skip multiple *
                }
                for (j = n; j >= 0 && !dp[j]; --j) {}
                for (; j >= 0; --j) {
                    dp[j] = true;
                }
            } else {
                for (j = 0; j < n + 1; ++j)
                    dp[j] = (p[i] == s[j] || p[i] == '?') ? dp[j + 1] : false;
            }
        }
        return dp[0];
    }
};
