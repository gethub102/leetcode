/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/
// DO NOT merge together!!!
class Solution {
  public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2 == 0) {
            return (findMedianSortedArraysBinarySearch(A, m, B, n, (m + n) / 2) + findMedianSortedArraysBinarySearch(A, m, B, n, (m + n) / 2 + 1)) / 2;
        } else {
            return findMedianSortedArraysBinarySearch(A, m, B, n, (m + n) / 2 + 1);
        }
    }

    double findMedianSortedArraysBinarySearch(int A[], int m, int B[], int n, int k) {
        if (m <= 0) {
            return B[k - 1];
        }
        if (n <= 0) {
            return A[k - 1];
        }
        if (k <= 1) {
            return min(A[0], B[0]);
        }
        if (B[n / 2] >= A[m / 2]) {
            if ((m / 2 + 1 + n / 2) >= k)  {
                return findMedianSortedArraysBinarySearch(A, m, B, n / 2, k);
            } else  {
                return findMedianSortedArraysBinarySearch(A + m / 2 + 1, m - (m / 2 + 1), B, n, k - (m / 2 + 1));
            }
        } else {
            if ((n / 2 + 1 + m / 2) >= k)  {
                return findMedianSortedArraysBinarySearch(A, m / 2, B, n, k);
            } else  {
                return findMedianSortedArraysBinarySearch(A, m, B + n / 2 + 1, n - (n / 2 + 1), k - (n / 2 + 1));
            }
        }
    }
};
