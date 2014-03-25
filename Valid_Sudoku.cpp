class Solution {
  public:
    bool isValidSudoku(vector<vector<char> >& board) {
        // each rows
        vector<vector<char> > columns(9);
        vector<vector<char> > smallBlock(9);
        for (int i = 0; i < board.size(); i++) {
            if (isValidVector(board[i]) == false) return false;
            for (int j = 0; j < board[0].size(); j++) {
                // each columns
                columns[j].push_back(board[i][j]);
                // each small blocks
                smallBlock[i / 3 * 3 + j / 3].push_back(board[i][j]);
            }
        }
        for (int k = 0; k < 9; k++) {
            if (isValidVector(columns[k]) == false) return false;
            if (isValidVector(smallBlock[k]) == false) return false;
        }
        return true;
    }

    bool isValidVector(vector<char> myVector) {
        for (int i = 1; i < 9; i++) {
            if (isdigit(myVector[i]) && find(myVector.begin(), myVector.begin() + i, myVector[i]) != myVector.begin() + i) return false;
        }
        return true;
    }
};
