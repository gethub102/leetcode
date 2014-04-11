class Solution {
  public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.size() == 0) return 0;
        vector<int> dp(triangle.size(), triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++) {
            dp[i] = dp[i - 1] + triangle[i][i];
            for (int j = i - 1; j >= 1; j--) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j - 1]);
            }
            dp[0] = dp[0] + triangle[i][0];

        }
        int result = INT_MAX;
        for (int k = 0; k < triangle.size(); k++) {
            result = min(result, dp[k]);
        }
        return result;
    }
};
