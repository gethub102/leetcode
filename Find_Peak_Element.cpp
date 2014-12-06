/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
*/
class Solution {
  public:
    int findPeakElement(const vector<int>& num) {
        if (num.empty() || num.size() == 1) {
            return 0;
        }
        if (num[0] > num[1]) {
            return 0;
        }
        if (num[num.size() - 1] > num[num.size() - 2]) {
            return num.size() - 1;
        }
        int begin = 0;
        int end = num.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) {
                return mid;
            } else if (num[mid] > num[mid - 1] && num[mid] < num[mid + 1]) {
                begin = mid;
            } else {
                end = mid;
            }
        }
        return begin;
    }
};
