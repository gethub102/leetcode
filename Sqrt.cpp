// newton rule

class Solution {
  public:
    int sqrt(int x) {
        // special cases
        if (x < 0) return -1;
        if (x == 0) return 0;
        // newton's method
        double last = 0;
        double res = 1;
        while (res != last) {
            last = res;
            res = (res + x / res) / 2;
        }
        return int(res);
    }
};

// binary
class Solution {
  public:
    int sqrt(int x) {
        long long start = 0;
        long long end = x / 2 + 1;
        while (start <= end)  {
            long long mid = start + (end - start) / 2;
            long long sq = mid * mid;
            if (sq == x) {
                return mid;
            } else if (sq < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return end;
    }
};

// Fast inverse square root
// from Quake III source code

float Q_rsqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * (long*) &y;                          // evil floating point bit level hacking
    i  = 0x5f3759df - (i >> 1);                 // what the fuck?
    y  = * (float*) &i;
    y  = y * (threehalfs - (x2 * y * y));       // 1st iteration
//      y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}
