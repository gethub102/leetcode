class Solution {
  public:
    bool search(int A[], int n, int target) {
        return searchRecursion(A, 0, n - 1, target);
    }

    bool searchRecursion(int A[], int begin, int end, int target) {
        if (begin > end) return false;
        if (begin == end) return A[begin] == target;
        int mid = begin + (end - begin) / 2;
        if (A[mid] == target) return true;
        if (A[begin] < A[mid] && begin != mid) {
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
        } else {
            return searchRecursion(A, begin, mid - 1, target) || searchRecursion(A, mid + 1, end, target);
        }
    }
};
