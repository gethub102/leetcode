class Solution {
  public:
    int reverse(int x) {
        int result = 0;
        bool negative = false;
        if (x < 0) {
            x = -x;
            negative = true;
        }
        while (x > 0) {
            result *= 10;
            result += (x % 10);
            x = x / 10;
        }
        if (negative) result = -result;
        return result;
    }
};
