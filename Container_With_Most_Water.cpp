/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
class Solution {
  public:
    int maxArea(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
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
