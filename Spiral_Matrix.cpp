class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int min_row = 0;
        int max_row = matrix.size() - 1;
        int min_column = 0;
        int max_column = matrix[0].size() - 1;
        int method = 0;
        int i, j;
        while (min_row <= max_row && min_column <= max_column) {
            if (method == 0) {
                // horizontal access min_row, left to right,and then min_row +1
                for (j = min_column; j <= max_column; j++) {
                    result.push_back(matrix[min_row][j]);
                }
                min_row += 1;
            } else if (method == 1) {
                // vertical access max_column, up to down, and then max_colum -1
                for (i = min_row; i <= max_row; i++) {
                    result.push_back(matrix[i][max_column]);
                }
                max_column -= 1;
            } else if (method == 2) {
                // horizontal access max_row, right to left, and then max_row -1
                for (j = max_column; j >= min_column; j--) {
                    result.push_back(matrix[max_row][j]);
                }
                max_row -= 1;
            } else if (method == 3) {
                // vertical access min_column, down to up, and then min_colum +1
                for (i = max_row; i >= min_row; i--) {
                    result.push_back(matrix[i][min_column]);
                }
                min_column += 1;
            }
            method = (method + 1) % 4;
        }
        return result;

    }
};
