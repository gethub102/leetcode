// should rewrite
class Solution {
  public:
    int search(int A[], int n, int target) {
        // spcial cases
        if (n <= 0) return -1;
        if (n == 1) return A[0] == target ? 0 : -1;
        // general case
        for (int i = 0; i < n; i++) {
            if (A[i] == target) return i;
        }
        return -1;
    }
};
