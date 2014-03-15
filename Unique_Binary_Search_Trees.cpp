class Solution {
public:
    int numTrees(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result = 2 * (2 * i - 1) * result / (i + 1);
        }
        return result;
    }
};
