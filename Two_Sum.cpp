class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        if (numbers.size() < 2) {
            return result;
        }
        map<int, int> dict;
        for (int i = 0; i < numbers.size(); i++) {
            if (dict.find(target - numbers[i]) != dict.end()) {
                result.push_back(dict[target - numbers[i]] + 1);
                result.push_back(i + 1);
                return result;
            } else {
                dict[numbers[i]] = i;
            }
        }
        // no pair
        return result;
    }
};
