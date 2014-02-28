class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        int i = 0;
        while (i < n) {
            result ^= A[i];
            i++;
        }
        return result;
    }
};
