class Solution {
public:
    int lengthOfLastWord(const char* s) {
        int count = 0;
        int result = 0;
        int index = 0;
        int length = strlen(s);
        while (index < length) {
            if (s[index] != ' ') {
                count ++;
                result = count;
            } else {
                count = 0;
            }
            index++;
        }
        return result;
    }
};
