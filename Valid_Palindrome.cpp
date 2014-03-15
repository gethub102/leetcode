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
