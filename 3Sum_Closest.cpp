class Solution {
  public:
    int threeSumClosest(vector<int>& num, int target) {
        if (num.size() < 3) return -1; // special case
        sort(num.begin(), num.end());
        int result =  num[0] + num[1] + num[num.size() - 1];
        for (int i = 0; i <= num.size() - 3; i++) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            int a = num[i];
            int b_index = i + 1;
            int c_index = num.size() - 1;
            while (b_index < c_index) {
                int b = num[b_index];
                int c = num[c_index];
                if (a + b + c == target) return target;
                else if (a + b + c > target) {
                    c_index--;
                    result = abs(a + b + c - target) < abs(result - target) ? (a + b + c) : result;
                } else {
                    b_index++;
                    result = abs(a + b + c - target) < abs(result - target) ? (a + b + c) : result;
                }
            }
        }
        return result;
    }
};
