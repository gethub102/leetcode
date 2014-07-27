/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
class Solution {
  public:
    string countAndSay(int n) {
        if (n < 2) {
            return "1";
        }
        string s = countAndSay(n - 1);
        int count = 1;
        string say = "";
        for (int i = 1; i < s.size(); i++, count++) {
            if (s[i] != s[i - 1]) {
                say += to_string(count) + s[i - 1];
                count = 0;
            }
        }
        say += to_string(count) + s.back();
        return say;
    }
};
