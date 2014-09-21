/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/
/*
*  this question is too weird!!!
*  DFS, time limit exceeded
*  BFS, run time error only for big test case
*  so have to use a loop
*/
class Solution {
  public:
    void solve(vector<vector<char>>& board) {

        int max_i = board.size() - 1;
        if (max_i == -1) return;
        int max_j = board[0].size() - 1;
        if (max_j == -1) return;

        for (int i = 0; i <= max_i; i++) {
            if (board[i][0]  == 'O')board[i][0]  = 'Y';
            if (board[i][max_j]   == 'O')board[i][max_j]  = 'Y';
        }
        for (int j = 0; j <= max_j; j++) {
            if (board[0][j]  == 'O')board[0][j]  = 'Y';
            if (board[max_i][j]   == 'O')board[max_i][j]  = 'Y';
        }
        bool switchFlag;
        do {
            switchFlag = false;
            for (int i = 1; i < max_i; i++) {
                for (int j = 1; j < max_j; j++) {
                    if (board[i][j] == 'O' &&
                            (
                                board[i - 1][j] == 'Y' ||
                                board[i + 1][j] == 'Y' ||
                                board[i][j - 1] == 'Y' ||
                                board[i][j + 1] == 'Y'
                            )) {
                        switchFlag = true;
                        board[i][j] = 'Y';
                    }
                }
            }
        } while (switchFlag);

        for (int i = 0; i <= max_i; i++) {
            for (int j = 0; j <= max_j; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};
