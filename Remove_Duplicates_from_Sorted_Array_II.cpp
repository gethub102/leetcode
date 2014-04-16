class Solution {
  public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int occur = 1;
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (A[res] == A[i]) {
                if (occur == 2) {
                    continue;
                }
                occur++;
            } else {
                occur = 1 ;
            }
            res++;
            A[res] = A[i];
        }
        return res + 1;
    }
};
