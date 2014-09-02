/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
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
