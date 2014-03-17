/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compareInterval(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), compareInterval);
        int n = intervals.size();
        int i = 0;
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
            while (i < n && intervals[i].start <= result.back().end) {
                result.back().end = max(result.back().end, intervals[i].end);
                i++;
            }
        }
        return result;
    }
};
