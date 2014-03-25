class Solution {
  public:
    void solveSudoku(vector<vector<char> >& board) {
        vector<vector<char> > originalCopy(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                originalCopy[i].push_back(board[i][j]);
            }
        }
        solveSudokuRecursion(originalCopy, board, 0, 0);
    }

    void solveSudokuRecursion(vector<vector<char> >& board, vector<vector<char> >& result, int row, int column) {
        // get solution
        if (row == board.size()) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    result[i][j] = board[i][j];
                }
            }
            return;
        }
        // else
        // already fill in ,goto next
        if (isdigit(board[row][column])) {
            solveSudokuRecursion(board, result, row + (column + 1) / 9, (column + 1) % 9);
            // empty, make to try;
        } else {
            vector<char> currentRow = board[row];
            vector<char> currentColumn ;
            vector<char> currentBlock ;
            int currentBlockNumber = row / 3 * 3 + column / 3;
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    // each column
                    if (j == column)currentColumn.push_back(board[i][j]);
                    // each small blocks
                    if (currentBlockNumber == i / 3 * 3 + j / 3)currentBlock.push_back(board[i][j]);
                }
            }
            // bool fallback = true;
            for (char i = '1'; i <= '9'; i++) {
                if (
                    // if row ok
                    find(currentRow.begin(), currentRow.end(), i) == currentRow.end()
                    // if column ok
                    && find(currentColumn.begin(), currentColumn.end(), i) == currentColumn.end()
                    // if block ok
                    && find(currentBlock.begin(), currentBlock.end(), i) == currentBlock.end()
                ) {
                    board[row][column] = i;
                    solveSudokuRecursion(board, result, row + (column + 1) / 9, (column + 1) % 9);
                    board[row][column] = '.'; // fallback
                }
            }
        }
    }
};
