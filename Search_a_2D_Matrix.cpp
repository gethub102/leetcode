class Solution {
  public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int height = matrix.size();
        if (height == 0) {
            return false;
        }
        int width = matrix[0].size();
        if (width == 0) {
            return false;
        }
        int i = 0;
        int j = width - 1;
        while (i < height && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return false;
    }
};
