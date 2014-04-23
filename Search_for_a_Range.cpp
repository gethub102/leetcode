class Solution {
  public:
    vector<int> searchRange(int A[], int n, int target) {
        return searchRangeRecursion(A, n , 0, n - 1, target);
    }

    vector<int> searchRangeRecursion(int A[], int size, int begin, int end, int target) {
        if (begin > end) {
            vector<int> result(2, -1);
            return result;
        } else if (begin == end) {
            if (A[begin] == target) {
                int range_start = begin;
                int range_end = begin;
                while (range_start > 0) {
                    if (A[range_start - 1] == target) range_start--;
                    else break;
                }
                while (range_end < size - 1) {
                    if (A[range_end + 1] == target) range_end++;
                    else break;
                }
                vector<int> result;
                result.push_back(range_start);
                result.push_back(range_end);
                return result;
            } else {
                vector<int> result(2, -1);
                return result;
            }
        } else {
            int mid = begin + (end - begin) / 2;
            if (A[mid] == target) {
                int range_start = mid;
                int range_end = mid;
                while (range_start > 0) {
                    if (A[range_start - 1] == target) range_start--;
                    else break;
                }
                while (range_end < size - 1) {
                    if (A[range_end + 1] == target) range_end++;
                    else break;
                }
                vector<int> result;
                result.push_back(range_start);
                result.push_back(range_end);
                return result;
            } else if (A[mid] > target) {
                return searchRangeRecursion(A, size, begin, mid - 1, target);
            } else {
                return searchRangeRecursion(A, size, mid + 1, end, target);
            }

        }
    }
};
