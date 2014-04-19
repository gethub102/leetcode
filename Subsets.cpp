class Solution {
  public:
    vector<vector<int> > subsets(vector<int>& S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result(1); // one empty subset
        for (int i = 0; i < S.size(); i++) {
            int j_max = result.size();
            for (int j = 0; j < j_max; j++) {
                vector<int> new_element = result[j];
                new_element.push_back(S[i]);
                result.push_back(new_element);
            }
        }
        return result;
    }
};
