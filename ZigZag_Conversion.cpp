class Solution {
  public:
    string convert(string s, int nRows) {
        if (nRows <= 1 || nRows >= s.length()) {
            return s;
        }
        vector<string> result(nRows);
        string resultString = "";
        int currentRow = 0;
        bool currentRowRaise = true;
        int index = 0;
        while (index < s.length()) {
            result[currentRow] = result[currentRow] + s.substr(index, 1);
            index++;
            if (currentRow == 0) {
                currentRowRaise = true;
            }
            if (currentRow == nRows - 1) {
                currentRowRaise = false;
            }
            if (currentRowRaise) {
                currentRow++;
            } else {
                currentRow--;
            }
        }
        for (int j = 0; j < result.size(); j++) {
            resultString += result[j];
        }
        return resultString;
    }
};
