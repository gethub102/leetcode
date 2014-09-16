/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/
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
