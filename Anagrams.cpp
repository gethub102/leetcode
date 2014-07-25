/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
class Solution {
  public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> result;
        if (strs.size() <= 1) {
            return result;
        }
        map<string, int> myMap;
        for (int i = 0; i < strs.size(); i++) {
            string current = strs[i];
            sort(current.begin(), current.end());
            if (myMap.find(current) != myMap.end()) {
                if (myMap[current] != -1) {
                    result.push_back(strs[myMap[current]]);
                    result.push_back(strs[i]);
                    myMap[current] = -1;
                } else {
                    result.push_back(strs[i]);
                }
            } else {
                myMap[current] = i;
            }
        }
        return result;
    }
};
