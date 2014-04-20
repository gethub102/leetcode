class Solution {
  public:
    vector<vector<int> > permute(vector<int>& num) {
        vector<vector<int> > result;
        if (num.size() <= 0) return result;
        vector<int> onesolution;
        permutationsDFS(result, onesolution, num);
        return result;
    }

    void permutationsDFS(vector<vector<int> >& result, vector<int> onesolution, vector<int> num) {
        if (onesolution.size() == num.size()) {
            result.push_back(onesolution);
            return;
        }
        for (int i = 0; i < num.size(); i++) {
            if (find(onesolution.begin(), onesolution.end(), num[i]) == onesolution.end()) {
                onesolution.push_back(num[i]);
                permutationsDFS(result, onesolution, num);
                onesolution.pop_back();
            }
        }
    }
};
