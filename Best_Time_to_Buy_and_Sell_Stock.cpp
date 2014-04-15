class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int max_value = prices.back();
        int max_profit = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            int delta = max_value - prices[i];
            max_profit = max(max_profit, delta);
            max_value = max(max_value, prices[i]);
        }
        return max_profit;
    }
};
