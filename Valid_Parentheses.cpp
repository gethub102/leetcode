/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
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
