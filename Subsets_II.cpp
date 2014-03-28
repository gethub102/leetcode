class Solution {
  public:
    vector<vector<int> > subsetsWithDup(vector<int>& S) {
        sort(S.begin(), S.end());
        vector<vector<int> > v(1);
        for (int i = 0; i < S.size(); ++i) {
            int j = v.size();
            while (j > 0) {
                j--;
                v.push_back(v[j]);
                v.back().push_back(S[i]);
            }
        }
        // remove duplicate
        sort(v.begin(), v.end());
        v.resize(distance(v.begin(), unique(v.begin(), v.end())));
        return v;
    }
};
