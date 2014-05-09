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
