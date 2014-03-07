class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> S;
        height.push_back(0);
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            if (S.empty() || height[i] > height[S.top()]) S.push(i);
            else {
                int tmp = S.top();
                S.pop();
                sum = max(sum, height[tmp] * (S.empty() ? i : i - S.top() - 1));
                i--;
            }
        }
        return sum;
    }
};