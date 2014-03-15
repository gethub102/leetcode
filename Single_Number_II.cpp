class Solution {
public:
    int singleNumber(int A[], int n) {
        int one = 0, two = 0;
        for (int i = 0; i < n; i++) {
            two |= A[i] & one;
            one ^= A[i];
            int t = one & two;
            one &= ~t;
            two &= ~t;
        }
        return one;
    }
};
