class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() < 1) return digits;
        vector<int> result(digits.begin(), digits.end());
        bool carry = true;
        for (int i = result.size() - 1; i >= 0; i--) {
            int tmp = result[i] + 1;
            if (tmp == 10) {
                result[i] = 0;
                carry = true;
            } else {
                result[i] = tmp;
                carry = false;
            }
            if (carry == false)break;
        }
        if (carry) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};
