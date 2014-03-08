class Solution {
public:
    void reverseWords(string& s) {
        if (s.empty())return;
        stack<string> stringStack;
        istringstream iss(s);
        string token;
        // split
        while (getline(iss, token, ' ')) {
            stringStack.push(token);
        }
        if (stringStack.empty())return;
        s = "";
        while (!stringStack.empty()) {
            // still some space, handle it here
            if (!stringStack.top().empty()) {
                s += stringStack.top();
                s += " ";
            }
            stringStack.pop();
        }
        // remove last space
        s = s.substr(0, s.length() - 1);
    }
};
