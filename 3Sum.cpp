/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
class Solution {
  public:
    vector<vector<int> > threeSum(vector<int>& num) {
        vector<vector<int> > result;
        if (num.size() < 3) {
            return result;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i <= num.size() - 3 && num[i] <= 0; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            int a = num[i];
            int b_index = i + 1;
            int c_index = num.size() - 1;
            while (b_index < c_index) {
                int b = num[b_index];
                int c = num[c_index];
                if (a + b + c == 0) {
                    vector<int> oneSolution;
                    oneSolution.push_back(a);
                    oneSolution.push_back(b);
                    oneSolution.push_back(c);
                    result.push_back(oneSolution);
                    b_index++;
                    c_index--;
                } else if (a + b + c > 0) {
                    c_index--;
                } else {
                    b_index++;
                }
            }
        }
        // remove duplicate
        result.resize(distance(result.begin(), unique(result.begin(), result.end())));
        return result;
    }
};
