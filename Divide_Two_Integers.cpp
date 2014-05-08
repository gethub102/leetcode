class Solution {
  public:
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;
        // can not write in one line, will overflow
        a = abs(a);
        b = abs(b);
        int res = 0;
        while (a >= b)  {
            long long t = b;
            for (int i = 1; a >= t; i <<= 1, t <<= 1) {
                a -= t;
                res += i;
            }
        }
        return ((dividend < 0) ^ (divisor < 0)) ? -res : res;
    }
};
