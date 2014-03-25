class Solution {
  public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<string> myStack;
        int i = 0;
        while (i < s.length()) {
            if (s.substr(i, 1) == "(" || s.substr(i, 1) == "[" || s.substr(i, 1) == "{") {
                myStack.push(s.substr(i, 1));
                i++;
            } else if (!myStack.empty() && (
                           (s.substr(i, 1) == ")" && myStack.top() == "(")
                           || (s.substr(i, 1) == "]" && myStack.top() == "[")
                           || (s.substr(i, 1) == "}" && myStack.top() == "{")
                       )) {
                myStack.pop();
                i++;
            } else {
                return false;
            }
        }
        return myStack.empty();
    }
};
