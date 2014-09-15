/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/
class Solution {
  public:
    bool isPalindrome(string s) {
        int begin = 0;
        int end = s.length() - 1;
        while (begin < end) {
            if (!isalpha(s[begin]) && !isdigit(s[begin])) {
                begin ++;
                continue;
            }
            if (!isalpha(s[end]) && !isdigit(s[end])) {
                end--;
                continue;
            }
            if (s[begin] == s[end] || abs(s[begin] - s[end]) == 32) {
                begin++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};
