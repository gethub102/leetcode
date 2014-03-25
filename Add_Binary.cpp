class Solution {
  public:
    string addBinary(string a, string b) {
        // special cases
        if (a.empty() && b.empty()) return "";
        if (a.empty() && !b.empty()) return b;
        if (!a.empty() && b.empty()) return a;
        // normal cases
        int a_index = a.length() - 1;
        int b_index = b.length() - 1;
        bool carry = false;
        string result = "";
        while (a_index >= 0 && b_index >= 0) {
            if (a[a_index] == '0' && b[b_index] == '0' && !carry) {
                result = "0" + result;
                carry = false;
            } else if (
                (a[a_index] == '0' && b[b_index] == '0' && carry) ||
                (a[a_index] == '0' && b[b_index] == '1' && !carry) ||
                (a[a_index] == '1' && b[b_index] == '0' && !carry)
            ) {
                result = "1" + result;
                carry = false;
            } else if (
                (a[a_index] == '0' && b[b_index] == '1' && carry) ||
                (a[a_index] == '1' && b[b_index] == '0' && carry) ||
                (a[a_index] == '1' && b[b_index] == '1' && !carry)
            ) {
                result = "0" + result;
                carry = true;
            } else if (a[a_index] == '1' && b[b_index] == '1' && carry) {
                result = "1" + result;
                carry = true;
            }
            a_index --;
            b_index --;
        }
        // now either a_index or b_index is zero
        // try a
        while (a_index >= 0) {
            if (!carry) {
                if (a[a_index] == '1')
                    result = "1" + result;
                else
                    result = "0" + result;
            } else if (a[a_index] == '1') {
                result = "0" + result;
                carry = true;
            } else if (a[a_index] == '0') {
                result = "1" + result;
                carry = false;
            }
            a_index--;
        }
        // try b
        while (b_index >= 0) {
            if (!carry) {
                if (b[b_index] == '1')
                    result = "1" + result;
                else
                    result = "0" + result;
            } else if (b[b_index] == '1') {
                result = "0" + result;
                carry = true;
            } else if (b[b_index] == '0') {
                result = "1" + result;
                carry = false;
            }
            b_index--;
        }
        // still carry
        if (carry) {
            result = "1" + result;
        }
        return result;
    }
};
