class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int low = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int profit = prices[i] - low;
            max_profit = max(max_profit, profit);
            low = min(low, prices[i]);
        }
        return max_profit;
    }
};