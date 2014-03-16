// should be a better solution, should rewrite
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int level = triangle.size();
        if (level == 0) return 0; //error
        if (level == 1) return triangle[0][0];
        // general case
        for (int i = 1; i < level; i++) {
            triangle[i][0] += triangle[i - 1].front();
            for (int j = 1; j < i; j++) {
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
            triangle[i][i] += triangle[i - 1].back();
        }
        sort(triangle.back().begin(), triangle.back().end());
        return triangle.back().front();
    }
};
