/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution {
  public:
    int romanToInt(string s) {
        if (s.length() == 0) {
            return 0
        };

        map<char, int> myMap;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int n = s.length();
        int sum = myMap[s[n - 1]];
        for (int i = n - 2; i >= 0; i--) {
            if (myMap[s[i + 1]] <= myMap[s[i]])
                sum += myMap[s[i]];
            else
                sum -= myMap[s[i]];
        }
        return sum;
    }
};
