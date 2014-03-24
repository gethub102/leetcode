class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& num, int target) {
        vector<vector<int> >  result;
        if (num.size() < 4) return result;
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
