class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        if (num.size() < 3) return result;
        for (int i = 0; i <= num.size() - 3; i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            for (int j = i + 1; j <= num.size() - 2; j++) {
                if (j > i + 1 && num[j] == num[j - 1]) continue;
                for (int k = j + 1; k <= num.size() - 1; k++) {
                    if (k > j + 1 && num[k] == num[k - 1])continue;
                    if (num[i] + num[j] + num[k] == 0) {
                        vector<int> newV;
                        newV.push_back(num[i]);
                        newV.push_back(num[j]);
                        newV.push_back(num[k]);
                        result.push_back(newV);
                    }
                }
            }
        }
        return result;
    }
};