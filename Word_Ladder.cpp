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
