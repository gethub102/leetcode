class Solution {
  public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        vector<string> result;
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
        if (checked[s.length()] == false)  return result;
        // 上面这一段是为了防止 aaaab，["a"] 根本没结果这种情况，下面就是正常的 DFS 了
        string oneSolution;
        wordBreakDFS(result, oneSolution, s, dict);
        return result;
    }

    void wordBreakDFS(vector<string>& result, string oneSolution, string s, unordered_set<string>& dict) {
        if (s.empty()) {
            result.push_back(oneSolution);
            return;
        }
        for (int i = s.length(); i >= 1; i--) {
            string substr = s.substr(0, i);
            if (dict.find(substr) != dict.end()) {
                string old_oneSolution = oneSolution;
                oneSolution = oneSolution.empty() ? substr : oneSolution + " " + substr;
                wordBreakDFS(result, oneSolution, s.substr(i), dict);
                oneSolution = old_oneSolution;
            }
        }
    }
};
