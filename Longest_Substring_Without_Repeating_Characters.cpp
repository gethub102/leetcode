class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int i = 0, len = 0, n = s.length();
        set<char> myset ;
        for (int j = 0; j < n; j++) { // 结尾元素
            if (myset.find(s[j]) != myset.end()) { //found dup
                len = max(len, (j - 1) - i + 1);
                while (i < n && s[i] != s[j]) { // remove abc from abcd123456d
                    myset.erase(s[i]);
                    i++;
                }
                i++; // remove d
            } else {
                myset.insert(s[j]);
            }
        }
        return max(len, n - i);
    }
};