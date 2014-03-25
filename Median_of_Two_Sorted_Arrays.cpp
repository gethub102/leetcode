class Solution {
  public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        vector<int> C;
        int i = 0;
        int j = 0;
        while (m && n && i < m && j < n) {
            if (A[i] <= B[j]) {
                C.push_back(A[i]);
                i++;
            } else {
                C.push_back(B[j]);
                j++;
            }
        }
        while (i < m) {
            C.push_back(A[i]);
            i++;
        }
        while (j < n) {
            C.push_back(B[j]);
            j++;
        }
        if (C.size() == 1) return C[0];
        if ((m + n) % 2 != 0) return (double)C[(m + n) / 2];
        else return ((double)(C[(m + n) / 2 - 1] + C[(m + n) / 2])) / 2;

    }
};
