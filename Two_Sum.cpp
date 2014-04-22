class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        if (numbers.size() <= 1)  {
            return result;
        }
        if (numbers.size() == 2) {
            if (numbers[0] + numbers[1] == target) {
                result.push_back(0);
                result.push_back(1);
            }
            return result;
        }
        // general case;
        map<int, int> mymap; // keep <numbers[i], i>
        for (int i = 0; i < numbers.size(); i++) {
            if (mymap.find(target - numbers[i]) != mymap.end()) {
                result.push_back(mymap[target - numbers[i]] + 1);
                result.push_back(i + 1);
                return result;
            } else {
                mymap[numbers[i]] = i;
            }
        }
    }
};
