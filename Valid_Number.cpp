class Solution {
public:
    bool isNumber(const char* s) {
        int i = 0;
        bool hasNum = false;
        bool hasE = false;
        bool hasPoint = false;
        bool hasSign = false;
        bool hasSpace = false;
        if (s[i] == '\0') return false;
        while (s[i] != '\0') {
            char c = s[i];
            if (!((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '.'  || c == 'e' || c == ' '))return false;
            if (c <= '9' && c >= '0') hasNum = true;
            if (hasE && c == 'e') return false;
            if (!hasNum && c == 'e')return false;
            if (hasNum && !hasE && c == 'e') {
                hasE = true;
                hasNum = false;
            }
            if (hasPoint && !hasE && c == '-') return false;
            if (hasPoint && !hasE && c == '+') return false;
            if (hasPoint && c == '.') return false;
            if (!hasPoint && c == '.') hasPoint = true;
            if (hasSign && (c == '+' || c == '-'))return false;
            if (!hasSign && (c == '+' || c == '-'))hasSign = true;
            if (hasSpace && c != ' ')return false;
            if ((hasNum || hasPoint || hasSign || hasE) && !hasSpace && c == ' ')hasSpace = true;
            if (hasE && c == '.')return false;
            if (hasSign && c == 'e')hasSign = false;
            if (hasNum && (c == '+' || c == '-')) return false;
            i++;
        }
        return hasNum;
    }
};
