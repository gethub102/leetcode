/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/
class Solution {
  public:
    vector<int> findSubstring(string S, vector<string>& L) {
        map<string, int> expectCount;
        map<string, int> realCount;
        for (int i = 0; i < L.size(); i++) {
            expectCount[L.at(i)]++;
        }
        vector<int> result;
        int row = L.size();
        if (row == 0) {
            return result;
        }
        int len = L[0].size();
        for (int i = 0; i < (int)S.size() - row * len + 1; i++) {
            realCount.clear();
            int j = 0;
            for (; j < row; j++) {
                string sub = S.substr(i + j * len, len);
                if (expectCount.find(sub) != expectCount.end()) {
                    realCount[sub]++;
                } else {
                    break;
                }
                if (realCount[sub] > expectCount[sub]) {
                    break;
                }
            }
            if (j == row) {
                result.push_back(i);
            }
        }
        return result;
    }
};
