class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > allsolutions;
        vector<int> currentSolution;
        solveNQueensRecursion(allsolutions, currentSolution, 0, n);
        return allsolutions;
    }

    // convert {1,3,0,2} to [".Q..",  "...Q","Q...","..Q."]
    vector<string> formatSolution(vector<int> solution) {
        vector<string> result(solution.size(), "");
        for (int i = 0; i < solution.size(); i++) {
            for (int j = 0; j < solution[i]; j++) {
                result[i] += ".";
            }
            result[i] += "Q";
            for (int j = solution[i] + 1; j < solution.size(); j++) {
                result[i] += ".";
            }
        }
        return result;
    }

    void solveNQueensRecursion(vector<vector<string> >& allsolutions,
                               vector<int>  currentSolution,
                               int currentLevel, int level) {
        // fill in finish, output
        if (currentLevel == level) {
            allsolutions.push_back(formatSolution(currentSolution));
            return;
        }
        // not finish yet.
        for (int i = 0; i < level; i++) {
            // if it is emtpy or i is in diffent column
            if (currentSolution.empty() || isValid(currentSolution, i)) {
                currentSolution.push_back(i);
                solveNQueensRecursion(allsolutions, currentSolution, currentLevel + 1, level);
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
