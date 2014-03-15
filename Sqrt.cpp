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
