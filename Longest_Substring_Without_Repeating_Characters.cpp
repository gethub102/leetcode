class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int checker = 0, val = 0, max = 0, j = 0, count = 0;
        for (int i = 0; i < s.size() && j < s.size(); i++) {
            j = i;
            while (j < s.size()) {
                val = s[j] - 'a';
                if ((checker & (1 << val)) > 0) break;
                checker |= 1 << val;
                j++;
                count++;
            }
            if (count > max) max = count;
            checker = 0;
            count = 0;
        }
        return max;
    }
};
