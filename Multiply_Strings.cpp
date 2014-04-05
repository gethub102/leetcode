class Solution {
  public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        // 先翻转，然后从乘法
        // 06 -> 60,07->70
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res(num1.size() + num2.size() + 1, '0');
        for (int i = 0; i < num1.size(); i++) {
            int dig1 = num1[i] - '0';
            int carry = 0;
            for (int j = 0; j < num2.size(); j++) {
                int dig2 = num2[j] - '0';
                int exist = res[i + j] - '0';
                res[i + j] = (dig1 * dig2 + carry + exist) % 10 + '0';
                carry = (dig1 * dig2 + carry + exist) / 10;
            }
            if (carry > 0) {
                res[i + num2.size()] = carry + '0';
            }
        }
        // 去掉 240000000 的 0000000
        while (res.size() > 1 && res[res.size() - 1] == '0') {
            res = res.substr(0, res.size() - 1);
        }
        // 最后翻转会42
        reverse(res.begin(), res.end());
        return res;
    }
};
