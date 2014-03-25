class Solution {
  public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> result;
        if (strs.size() <= 1) return result;
        map<string, int> anagram;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (anagram.find(s) == anagram.end()) {
                anagram.insert(make_pair(s, i));
            } else {
                if (anagram[s] >= 0) {
                    result.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};
