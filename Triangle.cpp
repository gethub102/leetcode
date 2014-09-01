/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class Solution {
  public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.size() == 0) {
            return 0;
        }
        vector<int> dp(triangle.size(), triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++) {
            dp[i] = dp[i - 1] + triangle[i][i];
            for (int j = i - 1; j > 0; j--) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j - 1]);
            }
            dp[0] = dp[0] + triangle[i][0];
        }
        int result = INT_MAX;
        for (int k = 0; k < dp.size(); k++) {
            result = min(result, dp[k]);
        }
        return result;
    }
};
