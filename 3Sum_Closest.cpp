/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
  public:
    int threeSumClosest(vector<int>& num, int target) {
        if (num.size() < 3) {
            return -1;   // special case
        }
        sort(num.begin(), num.end());
        int result =  num[0] + num[1] + num[num.size() - 1];
        for (int i = 0; i <= num.size() - 3; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            int a = num[i];
            int b_index = i + 1;
            int c_index = num.size() - 1;
            while (b_index < c_index) {
                int b = num[b_index];
                int c = num[c_index];
                if (a + b + c == target) {
                    return target;
                } else if (a + b + c > target) {
                    c_index--;
                    result = abs(a + b + c - target) < abs(result - target) ? (a + b + c) : result;
                } else {
                    b_index++;
                    result = abs(a + b + c - target) < abs(result - target) ? (a + b + c) : result;
                }
            }
        }
        return result;
    }
};
