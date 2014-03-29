class Solution {
  public:
    void nextPermutation(vector<int>& num) {
        assert(num.size() > 0);
        int index = num.size() - 1;
        while (index > 0) {
            if (num[index - 1] < num[index])break;
            index --;
        }
        if (index > 0) {
            int i = index - 1;
            int j = num.size() - 1;
            while (j > i) {
                if (num[j] > num[i]) break;
                j--;
            }
            swap(num[i], num[j]);
        }
        int begin = index;
        int end = num.size() - 1;
        while (begin < end) {
            swap(num[begin], num[end]);
            begin++;
            end--;
        }
    }
};
