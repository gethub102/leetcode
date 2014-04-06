class Solution {
  public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> oneSolution;
        partitionDFS(result, oneSolution, s);
        return result;
    }

    void partitionDFS(vector<vector<string>>& result, vector<string>& oneSolution, string s) {
        if (s.empty()) {
            result.push_back(oneSolution);
            return;
        }
        for (int i = s.length(); i >= 1; i--) {
            if (isPalindrome(s.substr(0, i))) {
                oneSolution.push_back(s.substr(0, i));
                partitionDFS(result, oneSolution, s.substr(i));
                oneSolution.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        if (s.empty()) return false;
        int begin = 0;
        int end = s.length() - 1;
        while (begin < end) {
            if (s[begin] != s[end]) return false;
            begin++;
            end--;
        }
        return true;
    }
};
