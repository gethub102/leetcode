class Solution {
  public:
    int searchInsert(int A[], int n, int target) {
        int start = 0, end = n - 1;
        while (start <= end)  {
            int mid = start + (end - start) / 2; // overflow
            if (A[mid] == target) return mid;
            if (mid > start && A[mid] > target && A[mid - 1] < target) return mid;
            if (A[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
