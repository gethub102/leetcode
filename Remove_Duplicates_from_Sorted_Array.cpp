class Solution {
  public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1)  return n;
        int res = 0;
        for (int i = 1; i < n; i++) {
            // 看到分歧加一下，剩下时候都不动
            if (A[i] != A[res]) {
                res++;
                if (res != i) A[res] = A[i];
            }
        }
        return res + 1;
    }
};
