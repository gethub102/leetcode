class Solution {
  public:
    int longestConsecutive(vector<int>& num) {
        // 这个排序是不对的
        /*
        if (num.size()<2) return num.size();
        sort(num.begin(),num.end());
        int result = 1;
        int length = 1;
        for(int i =0;i<num.size()-1;i++){
            if(num[i]==num[i+1]) continue;
            if(num[i]==num[i+1]-1) length++;
            else length =1;
            result = max(result,length);
        }
        return result;
        */
        // 应该用set
        set<int> myset;
        for (int i = 0; i < num.size(); i++) {
            myset.insert(num[i]);
        }
        int max_value = 0;
        while (!myset.empty()) {
            int length = 1;
            int current = *myset.begin();
            myset.erase(current);
            for (int i = current + 1; i <= INT_MAX; i++) {
                if (myset.find(i) != myset.end()) {
                    myset.erase(i);
                    length++;
                } else break;
            }
            for (int i = current - 1; i >= INT_MIN; i--) {
                if (myset.find(i) != myset.end()) {
                    myset.erase(i);
                    length++;
                } else break;
            }
            max_value = max(max_value, length);
        }
        return max_value;
    }
};