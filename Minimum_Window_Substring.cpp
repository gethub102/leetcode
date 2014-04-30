// DFS will cause Memory Limit Exceeded
class Solution {
  public:
    string minWindow(string S, string T) {
        map<char, int> T_has;
        map<char, int> now_we_has;

        // init hashtable
        for (int i = 0; i < T.length(); i++) {
            if (T_has.find(T[i]) != T_has.end()) {
                T_has[T[i]]++;
            } else {
                T_has[T[i]] = 1;
                now_we_has[T[i]] = 0;
            }
        }
        // for loop
        int count = 0;
        int minWinBegin = -1;
        int minWinEnd = S.length();
        int begin = 0;
        for (int end = 0; end < S.length(); end++) {
            char c = S[end];
            if (T_has.find(c) != T_has.end()) {
                now_we_has[c]++;
                if (now_we_has[c] <= T_has[c]) {
                    count++;
                }
                // find one valid substr
                if (count == T.length()) {
                    //while (1) S[begin] is useless char, (2) now_we_has[S[begin]]> T_has[S[begin]]
                    while (T_has.find(S[begin]) == T_has.end() || now_we_has[S[begin]] > T_has[S[begin]]) {
                        if ((T_has.find(S[begin]) != T_has.end() && now_we_has[S[begin]] > T_has[S[begin]])) {
                            now_we_has[S[begin]]--;
                        }
                        begin++;
                    }
                    if (end - begin < minWinEnd - minWinBegin) {
                        minWinEnd = end;
                        minWinBegin = begin;
                    }
                }
            }
        }
        return minWinBegin == -1 ? "" : S.substr(minWinBegin, minWinEnd - minWinBegin + 1);
    }
};
