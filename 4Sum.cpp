/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
class Solution {
  public:
    vector<vector<int> > fourSum(vector<int>& num, int target) {
        vector<vector<int> >  result;
        if (num.size() < 4) {
            return result;
        }
        sort(num.begin(), num.end());
        for (int i = 0; i <= num.size() - 4; i++) {
            //    if(i>0 && num[i-1]==num[i-1]) continue;
            int new_target = target - num[i];
            for (int j = i + 1; j <= num.size() - 3; j++) {
                //  if (j>1 && num[j]==num[j-1])continue;
                int a = num[j];
                int b_index = j + 1;
                int c_index = num.size() - 1;
                while (b_index < c_index) {
                    int b = num[b_index];
                    int c = num[c_index];
                    if (a + b + c == new_target) {
                        vector<int> oneSolution;
                        oneSolution.push_back(num[i]);
                        oneSolution.push_back(a);
                        oneSolution.push_back(b);
                        oneSolution.push_back(c);
                        result.push_back(oneSolution);
                        b_index++;
                        c_index--;
                    } else if (a + b + c > new_target) {
                        c_index--;
                    } else {
                        b_index++;
                    }
                }
            }
        }
        // remove duplicate
        sort(result.begin(), result.end());
        result.resize(distance(result.begin(), unique(result.begin(), result.end())));
    }
};
