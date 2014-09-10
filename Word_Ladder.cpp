/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/
class Solution {
  public:
    int ladderLength(string start, string end, unordered_set<string>& dict) {
        queue<string> q;
        q.push(start);
        int result = 1;
        while (!q.empty()) {
            int current_size = q.size();
            for (int i = 0; i < current_size; i++) {
                string current = q.front();
                for (int j = 0; j < current.length(); j++) {
                    for (char k = 'a'; k <= 'z'; k++) {
                        if (current[j] == k) continue;
                        string old_current = current;
                        current.replace(j, 1, string(1, k));
                        if (current == end) {
                            return result + 1;
                        } else if (dict.find(current) != dict.end()) {
                            dict.erase(current);
                            q.push(current);
                        }
                        current = old_current;
                    }
                }
                q.pop();
            }
            result++;
        }
        return 0;
    }
};
