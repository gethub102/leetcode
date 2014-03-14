class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n > 0) generator(result, "", 0, 0, n);
        return result;
    }

    void generator(vector<string>& result, string s, int left, int right, int n) {
        if (left == n) {
            // left is enough, now add right
            result.push_back(s.append(n - right, ')'));
            return;
        }
        // add left
        generator(result, s + '(', left + 1, right, n);
        // add right, only when left is more than right
        if (left > right) generator(result, s + ")", left, right + 1, n);
    }
};