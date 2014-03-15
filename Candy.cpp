class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() <= 1) return ratings.size();
        int i;
        vector<int> candy(ratings.size(), 1);
        int result = 0;
        for (i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }

        }
        for (i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1]) {
                candy[i] = candy[i + 1] + 1;
            }
        }
        for (i = 0; i < candy.size(); i++) {
            result += candy[i];
        }
        return result;
    }
};
