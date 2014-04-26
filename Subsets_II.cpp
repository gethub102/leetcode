class Solution {
  public:
    vector<vector<int> > subsetsWithDup(vector<int>& S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result(1);
        for (int i = 0; i < S.size(); i++) {
            int j_max = result.size();
            for (int j = 0; j < j_max; j++) {
                vector <int> new_element = result[j];
                new_element.push_back(S[i]);
                // add a check
                if (find(result.begin(), result.end(), new_element) == result.end()) {
                    result.push_back(new_element);
                }
            }
        }
        // remove duplicate
        // sort(v.begin(), v.end());
        // v.resize( distance(v.begin(), unique(v.begin(), v.end())) );
        return result;
    }
};
