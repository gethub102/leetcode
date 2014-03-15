// should rewrite
class Solution {
public:
    bool search(int A[], int n, int target) {
        // spcial cases
        if (n <= 0) return false;
        if (n == 1) return A[0] == target ? true : false;
        // general case
        for (int i = 0; i < n; i++) {
            if (A[i] == target) return true;
        }
        return false;
    }
};
