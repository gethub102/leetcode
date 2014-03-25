class Solution {
  public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.empty()) return false;
        int column = matrix[0].size() - 1;
        int row = 0;
        while (column >= 0 && row < matrix.size()) {
            if (matrix[row][column] == target) return true;
            else if (matrix[row][column] < target) row++;
            else column--;
        }
        return false;
    }
};
