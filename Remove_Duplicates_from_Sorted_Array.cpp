class Solution {
  public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1) return n;
        int i = 0;
        for (int j = 1; j < n; ++j) {
            if (A[j] != A[i]) {
                i++;
                if (i != j) {
                    A[i] = A[j];
                }
            }
        }
        return i + 1;
    }
};
