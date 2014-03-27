class Solution {
  public:
    int atoi(const char* str) {
        int result = 0;
        bool negative = false;
        int index = 0;
        // trim
        while (isspace(str[index])) {
            index++;
        }
        // positive or negative
        if (str[index] == '-') {
            negative = true;
            index++;
        } else if (str[index] == '+') {
            negative = false;
            index++;
        }
        while (index < strlen(str)) {
            if (isdigit(str[index])) {
                // handle overflow
                if ((result > 0 && result > INT_MAX / 10) || 10 * result > INT_MAX - (str[index] - '0')) {
                    return negative ? INT_MIN : INT_MAX;
                }
                result = 10 * result + (str[index] - '0');
                index++;
            } else {
                return negative ? -result : result;
            }
        }
        return negative ? -result : result;
    }
};
