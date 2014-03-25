class Solution {
  public:
    vector<vector<int> > generateMatrix(int n) {
        if (n <= 0) {
            vector<vector<int> > result;
            return result;
        }
        // init a n*n martix with all zero elements
        vector<vector<int> > result(n, vector<int>(n, 0));
        int min_row = 0;
        int max_row = n - 1;
        int min_column = 0;
        int max_column = n - 1;
        int method = 0;
        int i, j;
        int insertNum = 1;
        while (min_row <= max_row && min_column <= max_column) {
            if (method == 0) {
                // horizontal access min_row, left to right,and then min_row +1
                for (j = min_column; j <= max_column; j++) {
                    result[min_row][j] = insertNum;
                    insertNum++;
                }
                min_row += 1;
            } else if (method == 1) {
                // vertical access max_column, up to down, and then max_colum -1
                for (i = min_row; i <= max_row; i++) {
                    result[i][max_column] = insertNum;
                    insertNum++;
                }
                max_column -= 1;
            } else if (method == 2) {
                // horizontal access max_row, right to left, and then max_row -1
                for (j = max_column; j >= min_column; j--) {
                    result[max_row][j] = insertNum ;
                    insertNum++;
                }
                max_row -= 1;
            } else if (method == 3) {
                // vertical access min_column, down to up, and then min_colum +1
                for (i = max_row; i >= min_row; i--) {
                    result[i][min_column] = insertNum;
                    insertNum++;
                }
                min_column += 1;
            }
            method = (method + 1) % 4;
        }
        return result;
    }
};
