class Solution {
  public:
    vector<string> fullJustify(vector<string>& words, int L) {
        if (L == 0) return words;
        vector<string> result;
        int index = 1;
        string oneLine;
        oneLine = words[0];
        while (index < words.size()) {
            if (oneLine.empty()) {
                oneLine = words[index];
            } else {
                if (oneLine.length() + 1 + words[index].length() <= L) {
                    oneLine = oneLine + " " + words[index];
                } else {
                    result.push_back(formatLine(oneLine, L, false));
                    oneLine = words[index];
                }
            }
            index++;
        }
        // last line
        result.push_back(formatLine(oneLine, L, true));
        return result;
    }

    string formatLine(string input, int L, bool isLastLine) {
        if (input.length() == L) return input;
        if (input.empty()) {
            while (input.length() < L) input = input + " ";
            return input;
        }
        if (isLastLine) {
            while (input.length() < L) {
                input = input + " ";
            }
            return input;
        } else {
            if (input.find(" ") == -1) {
                while (input.length() < L) {
                    input = input + " ";
                }
            } else {
                int length_with_space = input.length();
                string buf; // Have a buffer string
                stringstream ss(input); // Insert the string into a stream
                vector<string> tokens; // Create vector to hold our words
                while (ss >> buf)tokens.push_back(buf);
                int length_of_space = tokens.size() - 1;
                int necessary_space = L - (length_with_space - length_of_space);
                int base_space_length  = necessary_space / length_of_space;
                int additional_space = necessary_space % length_of_space;
                string tmp = "";
                for (int i = 0; i < tokens.size() - 1; i++) {
                    tmp += tokens[i];
                    for (int j = 0; j < base_space_length; j++)tmp += " ";
                    if (i + 1 <= additional_space)tmp += " ";
                }
                tmp += tokens.back();
                input = tmp;
            }
            return input;
        }
    }
};
