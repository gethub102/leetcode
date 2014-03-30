class Solution {
  public:
    bool wordBreak(string s, unordered_set<string>& dict) {
        vector<bool> checked(s.length() + 1, false);
        checked[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (checked[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    checked[i] = true;
                    break;
                }
            }
        }
        return checked[s.length()];
    }
};
