class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> results;
        if (numbers.size() < 2) return results;
        else {
            vector<int> numbers_sorted(numbers);
            sort(numbers_sorted.begin(), numbers_sorted.end());
            for (int i = 0; i < numbers_sorted.size() - 1; i++) {
                if (find(numbers_sorted.begin() + i + 1, numbers_sorted.end(), target - numbers_sorted[i]) != numbers_sorted.end()) {
                    int m = find(numbers.begin(), numbers.end(), numbers_sorted[i]) - numbers.begin();
                    int n = find(numbers.begin(), numbers.end(), target - numbers_sorted[i]) - numbers.begin();
                    if (m == n) {
                        n = find(numbers.begin() + m + 1, numbers.end(), target - numbers_sorted[i]) - numbers.begin();
                    }
                    results.push_back(min(m + 1, n + 1));
                    results.push_back(max(m + 1, n + 1));
                    return results;
                }
            }
            return results;
        }
    }
};
