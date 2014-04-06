class Solution {
  public:
    /*

    第一个想法是 DFS，必须错。
    dp，公式如下
        r a b b i t
      1 0 0 0 0 0 0
    r 1 1 0 0 0 0 0
    a 1 1 1 0 0 0 0
    b 1 1 1 1 0 0 0
    b 1 1 1 2 1 0 0
    b 1 1 1 3 3 0 0
    i 1 1 1 3 3 3 0
    t 1 1 1 3 3 3 3

    先 生成矩阵，第一列都是 1，每次都先抄上一行，如果 s[i-1]==T[j-1]，则加上 dp[i-1][j-1]
    */
    int numDistinct(string S, string T) {
        if (S.empty() && T.empty()) return 1;
        if (S.empty()) return 0;
        if (T.empty()) return 1;
        vector<vector<int> > dp(S.length() + 1, vector<int>(T.length() + 1, 0));
        for (int k = 0; k < dp.size(); k++) {
            dp[k][0] = 1;
        }
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                dp[i][j] = dp[i - 1][j];
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[S.length()][T.length()];
    }
};
