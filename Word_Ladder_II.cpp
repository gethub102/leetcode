/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
class Solution {
    map<string, vector<string>> mp;
    vector<string> path;
    vector<vector<string>> res;
  public:

    void findDict(string str, unordered_set<string>& dict, unordered_set<string>& nxtlev) {
        //find the next level strings in the dict and add them in nxtlev
        if (str.empty() || dict.empty()) {
            return;
        }
        string cur;
        for (int i = 0; i < str.length(); ++i) {
            cur = str;
            for (char j = 'a'; j <= 'z'; ++j) {
                cur[i] = j;
                if (dict.find(cur) != dict.end()) {
                    // add str to cur's path list.
                    // update the nxtlev.
                    mp[cur].push_back(str);
                    nxtlev.insert(cur);
                }
            }
        }
    }

    void output(string start, string end) {
        if (start == end) {
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        } else {
            for (int i = 0; i < mp[end].size(); i++) {
                path.push_back(mp[end][i]);
                output(start, mp[end][i]);
                //need to pop the back out and get the new one in the same level.
                path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string>& dict) {
        mp.clear();
        path.clear();
        res.clear();
        //add start and end to the dictionary.
        dict.insert(start);
        dict.insert(end);
        unordered_set<string> curlev;
        curlev.insert(start);
        unordered_set<string> nxtlev;
        path.push_back(end);

        while (true) {
            for (auto it = curlev.begin(); it != curlev.end(); ++it) {
                dict.erase(*it);
            }
            for (auto it = curlev.begin(); it != curlev.end(); ++it) {
                findDict(*it, dict, nxtlev);
            }
            if (nxtlev.empty()) {
                return res;
            }
            if (nxtlev.find(end) != nxtlev.end()) {
                output(start, end);
                return res;
            }
            curlev.clear();
            curlev = nxtlev;
            nxtlev.clear();
        }
    }
};
