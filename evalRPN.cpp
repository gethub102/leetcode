class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) return stoi(tokens[0]);
        if (tokens.size() < 3) return -1; //error
        vector<int> result;
        for (int i = 0; i <= tokens.size() - 1; i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                result.push_back(stoi(tokens[i]));
            } else {
                if (result.size() < 2) return -1; // error
                int b = result[result.size() - 1];
                result.pop_back();
                int a = result[result.size() - 1];
                result.pop_back();
                if (tokens[i] == "+") result.push_back(a + b);
                else if (tokens[i] == "-") result.push_back(a - b);
                else if (tokens[i] == "*") result.push_back(a * b);
                else {
                    if (b == 0) return -1; //error
                    result.push_back(a / b);
                }
            }
        }
        if (result.size() != 1) return -1; //error
        else return result[0];
    }
};