class Solution {
  public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1)  {
            return n;
        }
        int index = 1;
        for (int i = 2; i < n; i++) {
            // if diff, add
            if (A[i] != A[index] || A[i] != A[index - 1]) {
                index++;
                A[index] = A[i];
            }
        }
        return index + 1;
    }
};
