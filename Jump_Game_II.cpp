/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/
class Solution {
  public:
    int jump(int A[], int n) {
        /* time limit exceed for big test case
        int dp[n];
        dp[n-1]=0;
        for(int i =n-2;i>=0;i--){
            // enough step to go;
            if(A[i]>=(n-1-i)) dp[i]=1;
            else {
                int more_step = INT_MAX;
                for(int j=1;j<=A[i];j++){
                    more_step = min(dp[i+j],more_step);
                }
                dp[i] = more_step +1;
            }
        }
        return dp[0];
        */
        if (n <= 1) return 0;
        int ret = 0;
        int cur = 0;
        int last = 0;
        // ok 这个题目是这样的，贪心
        for (int i = 0; i < n; i++) {
            // 哎呀，不够了，说明需要用之前一步的走法走到最远了，加上当前一步。所以是＋＋
            if (i > last) {
                last = cur;
                ret++;
            }
            //算当前可以走最远的多少，这个值留给下一个循环用
            cur = max(cur, i + A[i]);
        }
        return ret;
    }
};
