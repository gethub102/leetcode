class Solution {
  public:
    bool isMatch(const char* s, const char* p) {
        if (s == NULL || p == NULL) {
            return false;
        }
        if (*p == '\0') {
            return *s == '\0';
        }
        //出现.*
        if (*(p + 1) == '*') {
            // .* or match
            while ((*s != '\0' && *p == '.') || *s == *p) {
                if (isMatch(s, p + 2)) {
                    return true;
                }
                s++;
            }
            return isMatch(s, p + 2);
            //当前是正常匹配or.匹配
        } else if ((*s != '\0' && *p == '.') || *s == *p) {
            return isMatch(s + 1, p + 1);
        } else {
            return false;
        }
    }
};
