/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
class Solution {
  public:
    int searchInsert(int A[], int n, int target) {
        if (n <= 0) {
            return 0;
        }
        if (target <= A[0]) {
            return 0;
        }
        if (target > A[n - 1]) {
            return n;
        }
        int start = 0, end = n - 1;
        while (start <= end)  {
            int mid = start + (end - start) / 2; // overflow
            if (A[mid] == target) {
                return mid;
            }
            if (mid > start && A[mid] > target && A[mid - 1] < target) {
                return mid;
            }
            if (A[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
