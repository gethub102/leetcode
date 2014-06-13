/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        vector<int> found(256, 0); // number of char found
        int start = 0, end = 0, maxlen = 0;

        while (end < s.size()) {
            if (found[s[end]] == 0) {
                found[s[end]]++;
                end++;
                maxlen = max(maxlen, end - start);
            } else {
                found[s[start]]--;
                start++;
            }
        }
        return maxlen;
    }
};