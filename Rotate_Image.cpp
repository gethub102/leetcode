class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int len = matrix.size();
        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - i; j++) {
                swap(matrix[i][j], matrix[len - 1 - j][len - 1 - i]);
            }
        }
        for (int i = 0; i < len / 2; i++) {
            for (int j = 0; j < len; j++) {
                swap(matrix[i][j], matrix[len - i - 1][j]);
            }
        }
    }
};