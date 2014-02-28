class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x >= 0 && x <= 9) return true;
        int n = x;
        int rev = 0;
        while (x > 0) {
            int dig = x % 10;
            rev = rev * 10 + dig;
            x = x / 10;
        }
        return rev == n;
    }
};
