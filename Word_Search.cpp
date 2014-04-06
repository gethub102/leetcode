class Solution {
  public:
    // 本来一道很简单的 dfs，按照惯性又用了 void，直接 bool return 多快
    // 填成 # 的思路也很好，需要反省
    bool dfs(vector<vector<char> >& board, int i, int j, string& s, int index) {
        if (index == s.size())return true;

        if (i > 0 && board[i - 1][j] == s[index]) {
            board[i - 1][j] = '#';
            if (dfs(board, i - 1, j, s, index + 1))return true;
            board[i - 1][j] = s[index];
        }

        if (i + 1 < board.size() && board[i + 1][j] == s[index]) {
            board[i + 1][j] = '#';
            if (dfs(board, i + 1, j, s, index + 1))return true;
            board[i + 1][j] = s[index];
        }

        if (j > 0 && board[i][j - 1] == s[index]) {
            board[i][j - 1] = '#';
            if (dfs(board, i, j - 1, s, index + 1))return true;
            board[i][j - 1] = s[index];
        }
        if (j + 1 < board[0].size() && board[i][j + 1] == s[index]) {
            board[i][j + 1] = '#';
            if (dfs(board, i, j + 1, s, index + 1))  return true;
            board[i][j + 1] = s[index];
        }
        return false;
    }

    bool exist(vector<vector<char> >& board, string word) {
        int row = board.size();
        if (row == 0)  return false;
        int col = board[0].size();
        bool result = false;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    if (dfs(board, i, j, word, 1))result =  true;
                    board[i][j] = word[0];
                    if (result) return true;
                }
            }
        return false;
    }
};
