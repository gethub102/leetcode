class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        if (num.size() < 2) return num.size();
        sort(num.begin(), num.end());
        int result = 1;
        int length = 1;
        for (int i = 0; i < num.size() - 1; i++) {
            if (num[i] == num[i + 1]) continue;
            if (num[i] == num[i + 1] - 1) length++;
            else length = 1;
            result = max(result, length);
        }
        return result;
    }
};
