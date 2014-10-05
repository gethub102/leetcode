/*
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1].


[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
Note:
Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        vector<int> array;
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                array[j] = array[j - 1] + array[j];
            }
            array.push_back(1);
        }
        return array;
    }
};
