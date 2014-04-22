/* 这个题的坑爹之处在于正常i从0~last, j从0~last那么循环不行。
* 因为d[i][j]用到了d[i + 1][j - 1]，说明i要从后往前，j则要从前往后。导致二层循环是这种顺序：
* for (int i = last; i >= 0; i–)
* for(int j = i; j  <= last; j++)
* 另外 vector 比 数组慢，这题用 vector 必超时
*/
class Solution {
  public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int length  = s.length();
        if (length == 1) {
            return s;
        }
        bool dp[length][length];
        int start = 0;
        int end = 0;
        int max_length = 1;
        for (int i = length - 1; i >= 0; i--) {
            for (int j = i; j <= length - 1; j++) {
                if (i == j) {
                    dp[i][j] = true;
                    continue;
                } else if (i + 1 == j) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];

                }
                if (dp[i][j]  &&  j - i + 1 > max_length) {
                    max_length = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};
