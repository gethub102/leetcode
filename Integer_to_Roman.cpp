class Solution {
  public:
    string intToRoman(int num) {
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result = "";
        int i = 0;
        while (num > 0) {
            int times = num / nums[i];
            num -= nums[i] * times;
            for (; times > 0; times--) {
                result = result + symbols[i];
            }
            i++;
        }
        return result;
    }
};
