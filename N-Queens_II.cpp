class Solution {
public:
    int totalNQueens(int n) {
        int allSolutions = 0;
        vector<int> currentSolution;
        solveNQueensRecursion(allSolutions, currentSolution, 0, n);
        return allSolutions;
    }

    void solveNQueensRecursion(int& allSolutions,
                               vector<int>  currentSolution,
                               int currentLevel, int level) {
        // fill in finish, output
        if (currentLevel == level) {
            allSolutions++;
            return;
        }
        // not finish yet.
        for (int i = 0; i < level; i++) {
            // if it is emtpy or i is in diffent column
            if (currentSolution.empty() || isValid(currentSolution, i)) {
                currentSolution.push_back(i);
                solveNQueensRecursion(allSolutions, currentSolution, currentLevel + 1, level);
                currentSolution.pop_back();
            }
        }
    }

    bool isValid(vector<int>  currentSolution, int newPostion) {
        bool flag_column = find(currentSolution.begin(), currentSolution.end(), newPostion) == currentSolution.end();
        vector<int> diagonal_one, diagonal_two;
        for (int i = 0; i < currentSolution.size(); i++) {
            diagonal_one.push_back(i + currentSolution[i]);
            diagonal_two.push_back(i - currentSolution[i]);
        }
        bool flag_diagonal_one = find(diagonal_one.begin(), diagonal_one.end(), currentSolution.size() + newPostion) == diagonal_one.end();
        bool flag_diagonal_two = find(diagonal_two.begin(), diagonal_two.end(), currentSolution.size() - newPostion) == diagonal_two.end();
        return flag_column && flag_diagonal_one && flag_diagonal_two;
    }
};
