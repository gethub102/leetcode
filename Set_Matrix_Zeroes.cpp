class Solution {
  public:
    void setZeroes(vector<vector<int> >& matrix) {
        vector<bool> rowZeros(matrix.size(), false);
        vector<bool> columnsZeros(matrix[0].size(), false);
        int i, j;
        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    rowZeros[i] = true;
                    columnsZeros[j] = true;
                }
            }
        }
        for (i = 0; i < matrix.size(); i++) {
            for (j = 0; j < matrix[i].size(); j++) {
                if (rowZeros[i] || columnsZeros[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
