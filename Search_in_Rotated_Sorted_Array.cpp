class Solution {
  public:
    int search(int A[], int n, int target) {
        return   searchRecursion(A, 0, n - 1, target);
    }

    int searchRecursion(int A[], int begin, int end, int target) {
        if (begin > end) return -1;
        if (begin == end) return A[begin] == target ? begin : -1;
        int mid = begin + (end - begin) / 2;
        if (A[mid] == target) return mid;
        if (A[begin] < A[mid]) {
            if (A[begin] <= target && target <= A[mid]) {
                return searchRecursion(A, begin, mid - 1, target);
            } else {
                return searchRecursion(A, mid + 1, end, target);
            }
        } else if (A[mid] < A[end]) {
            if (A[mid] <= target && target <= A[end]) {
                return searchRecursion(A, mid + 1, end, target);
            } else {
                return searchRecursion(A, begin, mid - 1, target);
            }
        } else { // a[begin] == a[mid], directly search right
            return searchRecursion(A, mid + 1, end, target);
        }
    }
};
