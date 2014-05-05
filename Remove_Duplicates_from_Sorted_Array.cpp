class Solution {
  public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1)  {
            return n;
        }
        int index = 0;
        for (int i = 1; i < n; i++) {
            // if diff, add
            if (A[i] != A[index]) {
                index++;
                A[index] = A[i];
            }
        }
        return index + 1;
    }
};
