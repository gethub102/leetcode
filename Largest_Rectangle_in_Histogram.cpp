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
            if (height.size() == 0) {
                return 0;
            }
            stack<int> myStack;
            int result = 0;
            for (int i = 0; i <= height.size(); i++) {
                int curt = (i == height.size()) ? -1 : height[i];
                while (!myStack.empty() && curt <= height[myStack.top()]) {
                    int h = height[myStack.top()];
                    myStack.pop();
                    int w = myStack.empty() ? i : i - myStack.top() - 1;
                    result = max(result, h * w);
                }
                myStack.push(i);
            }
            return result;
        }
    }
};
