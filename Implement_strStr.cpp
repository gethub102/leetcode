class Solution {
  public:
    char* strStr(char* haystack, char* needle) {
        char* a = haystack;
        char* b = needle;
        while (true) {
            // b 到头了，找到了
            if (!*b) return haystack;
            // a 到头了，没有
            else if (!*a) return NULL;
            // 每一个指针比较，如果有不对的
            else if (*a++ != *b++) {
                // 如果出现不等的情况，原来的 haystack 指针向后走一个
                haystack++;
                // a 指向 haystack的新头，b指向needle老头，再来
                a = haystack;
                b = needle;
            }
        }
    }
};
