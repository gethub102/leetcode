class Solution {
  public:
    string getPermutation(int n, int k) {
        string result;
        vector<int> element;
        for (int i = 1; i <= n; i++) {
            element.push_back(i);
        }
        vector<int> fact;
        fact.push_back(1); // fact[0]
        for (int i = 1; i < n; i++) {
            fact.push_back(fact.back()*i);
        }
        k = k - 1; // 这里减去1，是原来的算法是从0开始的，leetcode从1开始
        for (int i = 0; i < n; i++) {
            // 这里只能背了，字典序算法
            result =  result + to_string(element[k / fact[n - 1 - i]]);
            element.erase(element.begin() + k / fact[n - 1 - i]);
            k = k % fact[n - 1 - i];
        }
        return result;
    }
};
