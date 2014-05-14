// dp
// num[i] = for loop( sum(num[0...k] x num[k...i]))

class Solution {
  public:
    int numTrees(int n) {
        vector<int> num(n + 1, 0);
        num[0] = 1;
        num[1] = 1;
        for (int i = 2 ; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                num[i] += num[j] * num[i - j - 1];
            }
        }
        return num[n];
    }
};
