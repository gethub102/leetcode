/*
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/
class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x >= 0 && x <= 9) {
            return true;
        }
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
