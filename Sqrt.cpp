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
