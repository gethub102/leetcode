class Solution {
  public:
    int largestRectangleArea(vector<int>& height) {
        int solution = 2; // solution 1 is O(n*n) - something, solution 2 is O(n)
        // brute force , cut some same
        if (solution == 1) {
            int result = 0;
            for (int end = 0; end < height.size(); end++) {
                if (end + 1 < height.size() && height[end + 1] >= height[end]) {
                    continue;
                }
                int min_height = height[end];
                for (int begin = end; begin >= 0; begin--) {
                    min_height = min(min_height, height[begin]);
                    result = max(result, min_height * (end - begin + 1));
                }
            }
            return result;
        } else if (solution == 2) {
            // maintain a stack
            stack<int> mystack;
            height.push_back(0);
            int result = 0;
            for (int i = 0; i < height.size(); i++) {
                if (mystack.empty() || height[mystack.top()] <= height[i]) {
                    mystack.push(i);
                } else {
                    int tmp = mystack.top();
                    mystack.pop();
                    int width;
                    if (mystack.empty()) {
                        width = i;
                    } else {
                        width = i - mystack.top() - 1;
                    }
                    i--;
                    result = max(result, height[tmp] * width);
                }
            }
            return result;
        }
    }
};
