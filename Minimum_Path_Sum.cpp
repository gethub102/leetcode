class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int rows = grid.size();
        if (rows == 0) return -1;
        int columns = grid[0].size();
        if (columns == 0) return -1;
        vector<int> steps(columns, INT_MAX);
        steps[0] = 0;
        for (int i = 0; i < rows; i++) {
            steps[0] = steps[0] + grid[i][0];
            for (int j = 1; j < columns; j++) {
                steps[j] = min(steps[j], steps[j - 1]) + grid[i][j];
            }
        }
        return steps[columns - 1];
    }
};
