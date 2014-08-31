/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
class Solution {
  public:
    int singleNumber(int A[], int n) {
        /* set<int> myset;
        for (int i = 0; i < n; i++) {
            if (myset.find(A[i]) == myset.end()) {
                myset.insert(A[i]);
            } else {
                myset.erase(A[i]);
            }
        }
        return *myset.begin();
        */
        int result = 0;
        int i = 0;
        while (i < n) {
            result ^= A[i];
            i++;
        }
        return result;
    }
};
