class Solution {
  public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        int times = 1;
        string result = "1";
        while (times < n) {
            vector<string> stringV;
            vector<int> countV;
            int index = 0;
            while (index < result.length()) {
                if (stringV.empty() || stringV.back() != result.substr(index, 1)) {
                    stringV.push_back(result.substr(index, 1));
                    countV.push_back(1);
                } else {
                    countV[countV.size() - 1] ++;
                }
                index++;
            }
            result = "";
            while (!stringV.empty()) {
                result = stringV.back() + result;
                result = to_string(countV.back()) + result;
                stringV.pop_back();
                countV.pop_back();
            }
            times++;
        }
        return result;
    }
};
