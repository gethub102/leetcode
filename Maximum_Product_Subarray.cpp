/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
class Solution {
  public:
    int maxProduct(int A[], int n) {
        if (n < 1) {
            return -1;
        }
        if (n == 1) {
            return A[0];
        }
        int maxPosValEndsWithLast = 0;
        int minNegValEndsWithLast = 0;
        int maxVal = 0;
        int minVal = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > 0) {
                maxPosValEndsWithLast = max(maxPosValEndsWithLast * A[i], A[i]);
                minNegValEndsWithLast = min(minNegValEndsWithLast * A[i], A[i]);
            } else if (A[i] < 0) {
                int temp = maxPosValEndsWithLast; //注意保存临时现场
                maxPosValEndsWithLast = minNegValEndsWithLast * A[i];
                minNegValEndsWithLast = min(temp * A[i], A[i]);
            } else { //A[i]==0
                maxPosValEndsWithLast = 0;
                minNegValEndsWithLast = 0;
            }
            //update
            maxVal = max(maxVal, maxPosValEndsWithLast);
            minVal = min(minVal, minNegValEndsWithLast);
        }
        return maxVal;
    }
};
