class Solution {
  public:
    void merge(int A[], int m, int B[], int n) {
        if (n == 0) return;
        if (m == 0) {
            for (int i = 0; i < n; i++) {
                A[i] = B[i];
            }
            return;
        }
        int index_a = m - 1;
        int index_b = n - 1;
        int index_all = m + n - 1;
        while (index_a >= 0 && index_b >= 0) {
            if (A[index_a] < B[index_b]) {
                A[index_all] = B[index_b];
                index_all--;
                index_b--;
            } else  {
                A[index_all] = A[index_a];
                index_all--;
                index_a--;
            }
        }
        while (index_b >= 0) {
            A[index_b] = B[index_b];
            index_b--;
        }
    }
};
