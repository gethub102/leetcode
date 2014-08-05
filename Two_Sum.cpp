/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
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
