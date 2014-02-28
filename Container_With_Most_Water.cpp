class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.empty()) return 0;
        int begin = 0, end = height.size() - 1, result = 0, contain;
        while (begin < end) {
            contain = min(height[begin], height[end]) * (end - begin);
            result = max(result, contain);
            if (height[begin] < height[end]) {
                begin++;
            } else {
                end--;
            }
        }
        return result;
    }
};
