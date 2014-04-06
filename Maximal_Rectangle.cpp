class Solution {
  public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        // 理解错题了，不是求一个矩阵，里面包含了原矩阵所有的1
        // 而是求以 1 组合的矩阵，最大的那个的 area
        //
        // 然后是一种解法超时，这种解法的是这样的生成一个 dp[m][n]
        // 值是当前这一行，以m n 结尾，有多少个连续的 1 了，如果matrix[m][n]==0,dp[m][n]=0
        // 整个扫完之后，再扫，这次是扫 dp，如果 dp[m][n]不是1，往上往下扫，如果同一列还是大于等于它，说明是矩形算高度，求面积
        // 这种算法的问题是大数据超时
        //
        // 怎么办？用Largest Rectangle in Histogram 求解。
        // Largest Rectangle in Histogram  是求一个 non negative arrary 的最大面积，这样想：
        // 生成一个长度是 martrix[0].size() 的 array，每一个value就是这一往上数连续的列的1的个数。
        // 一秒变老题目
        if (matrix.empty()) return 0;
        vector<int> thisRowHeight(matrix[0].size(), 0);
        int max_value = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    thisRowHeight[j] = thisRowHeight[j] + 1;
                } else {
                    thisRowHeight[j] = 0;
                }

            }
            // 这里第一次想半天，写到 for j 里面去了，败笔
            max_value = max(max_value, largestRectangleArea(thisRowHeight));
        }
        return max_value;
    }

    int largestRectangleArea(vector<int>& height) {
        stack<int> S;
        height.push_back(0);
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            if (S.empty() || height[i] > height[S.top()]) {
                S.push(i);
            } else {
                int tmp = S.top();
                S.pop();
                sum = max(sum, height[tmp] * (S.empty() ? i : i - S.top() - 1));
                i--;
            }
        }
        return sum;
    }
};
