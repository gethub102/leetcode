/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

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

// rewrite

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;   // DON'T forget it
        }
        int currentMax = prices.back();
        int result = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            result = max(result, currentMax - prices[i]);
            currentMax = max(currentMax, prices[i]);
        }
        return result;
    }
};
