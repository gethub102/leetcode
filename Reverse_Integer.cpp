class Solution {
  public:
    int reverse(int x) {
        bool negative = false;
        if (x == INT_MIN) return -1; // overflow
        if (x < 0) {
            x = -x;
            negative = true;
        }
        int result = 0;
        while (x) {
            if (result >= INT_MAX / 10 || INT_MAX - x % 10 < 10 * result) return -1; // overflow check
            result = 10 * result + x % 10;
            x = x / 10;
        }
        return negative ? -result : result;
    }
};
