class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int rows = obstacleGrid.size();
        if (rows == 0) return 0;
        int columns = obstacleGrid[0].size();
        if (columns == 0) return 0;
        if (obstacleGrid[0][0] == 1 || obstacleGrid[rows - 1][columns - 1] == 1) return 0;
        vector<int> dp(columns, 0);
        // first level
        for (int i = 0; i < columns; i++) {
            if (obstacleGrid[0][i] == 1) break;
            dp[i] = 1;
        }
        // from second level
        for (int i = 1; i < rows; i++) {
            // first element
            if (obstacleGrid[i][0] == 1) dp[0] = 0;
            // else dp[0]=d[0]; no change
            // from second element
            for (int j = 1; j < columns; j++) {
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else dp[j] += dp[j - 1];
            }
        }
        return dp.back();
    }
};
