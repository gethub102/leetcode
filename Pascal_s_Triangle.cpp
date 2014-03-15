class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        for (int i = 1; i <= numRows; i++) {
            vector<int> tmp(i, 1);
            for (int j = 1; j < i - 1; j++) {
                tmp[j] = result[i - 2][j] + result[i - 2][j - 1];
            }
            result.push_back(tmp);
        }
        return result;
    }
};
