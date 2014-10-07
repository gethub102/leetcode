/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> profitFromBeginToI(prices.size(), 0);
        vector<int> profitFromIToEnd(prices.size(), 0);
        getProfitFromBeginToI(prices, profitFromBeginToI);
        getProfitFromIToEnd(prices, profitFromIToEnd);
        int maxProfit = profitFromBeginToI[prices.size() - 1];
        for (int i = 1; i < prices.size() - 1; i++) {
            // 这里一定要错开加
            maxProfit = max(maxProfit, profitFromBeginToI[i] + profitFromIToEnd[i + 1]);
        }
        return maxProfit;
    }

    // 从【0】到【i】的最大 profit
    void getProfitFromBeginToI(vector<int>& prices, vector<int>& result) {
        //vector<int> result;
        //result.push_back(0); // result[0]==0;
        int min_value = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - min_value);
            min_value = min(min_value, prices[i]);
            result[i] = maxProfit;
        }
        //return result;
    }

    // 从【i】到尾巴的最大 profit
    void getProfitFromIToEnd(vector<int>& prices, vector<int>& result) {
        //vector<int> result(prices.size(),0);
        int max_value = prices.back();
        int maxProfit = 0;
        for (int i = prices.size() - 1; i >= 0; i--) {
            maxProfit = max(maxProfit, max_value - prices[i]);
            max_value = max(max_value, prices[i]);
            result[i] = maxProfit;
        }
        // return result;
    }
};
