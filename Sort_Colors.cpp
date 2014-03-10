class Solution {
public:
    void sortColors(int A[], int n) {
        int pivot = 1;
        int smaller = 0, equal = 0, larger = n - 1;
        while (equal <= larger) {
            if (A[equal] < pivot) {
                swap(A[smaller++], A[equal++]);
            } else if (A[equal] == pivot) {
                equal++;
            } else {
                swap(A[equal], A[larger--]);
            }
        }
    }
};