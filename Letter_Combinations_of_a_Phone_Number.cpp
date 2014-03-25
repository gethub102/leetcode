class Solution {
  public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            result.push_back("");
            return result;
        }
        map<char, string> dict;
        dict['1'] = "";
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";
        dict['0'] = " ";
        int index = 0;
        while (index < digits.length()) {
            if (isdigit(digits[index])) {
                // result is empty, add new word
                if (result.empty()) {
                    for (int i = 0; i < dict[digits[index]].size(); i++) {
                        result.push_back(dict[digits[index]].substr(i, 1));
                    }
                    // result is not empty, append
                } else {
                    int size = result.size();
                    for (int i = 0; i < size; i++) {
                        string head = result[0];
                        for (int j = 0; j < dict[digits[index]].size(); j++) {
                            result.push_back(head + dict[digits[index]].substr(j, 1));
                        }
                        result.erase(result.begin());
                    }
                }
            }
            index++;
        }
        return result;
    }
};
