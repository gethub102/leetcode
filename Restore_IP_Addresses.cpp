class Solution {
  public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        string oneSolution;
        restoreIpAddressesDFS(results, oneSolution, s, 0);
        return results;
    }

    void restoreIpAddressesDFS(vector<string>& results, string oneSolution, string s, int byte) {
        if (byte == 4) {
            if (s.empty()) {
                results.push_back(oneSolution);
            }
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (i <= s.length() && isValidIP(s.substr(0, i))) {
                string old_oneSolution = oneSolution;
                oneSolution = oneSolution.empty() ? s.substr(0, i) : oneSolution + "." + s.substr(0, i);
                restoreIpAddressesDFS(results, oneSolution, s.substr(i), byte + 1);
                oneSolution = old_oneSolution;
            }
        }
    }

    bool isValidIP(string s) {
        if (s.length() > 1 && s[0] == '0') {
            return false;   // case 001,is false
        }
        int value = stoi(s);
        return value >= 0 && value <= 255;
    }
};
