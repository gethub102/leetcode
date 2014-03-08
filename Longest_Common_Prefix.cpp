class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // special case
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        if (strs.size() > 2) {
            string first = strs.back();
            strs.pop_back();
            string second = longestCommonPrefix(strs);
            vector<string> two;
            two.push_back(first);
            two.push_back(second);
            return longestCommonPrefix(two);
        }
        string first = strs[0];
        string second = strs[1];
        if (first.empty() || second.empty()) return "";
        int i = 0;
        string result = "";
        int max = min(first.length(), second.length()) - 1;
        while (i <= max) {
            if (first[i] == second[i]) {
                result += first.substr(i, 1);
            } else {
                break;
            }
            i++;
        }
        return result;
    }
};