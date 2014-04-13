/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
  public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return   points.size();
        int max_value = 2;
        for (int i = 0; i < points.size() - 2; i++) {
            int vertical = 1 ; //
            unordered_map<double, int> myhash;
            myhash.clear();
            int max_hash = 0;
            int same_point = 0;
            Point point_a = points[i];
            for (int j = i + 1; j < points.size(); j++) {
                Point point_b = points[j];
                int delta_x = points[i].x - points[j].x;
                int delta_y = points[i].y - points[j].y;
                if (delta_x == 0 && delta_y == 0) {
                    same_point++;
                }
                if (delta_x == 0 && delta_y != 0) {
                    vertical++;
                } else {
                    //int delta_y = points[i].y-points[j].y;
                    double slope = (double)delta_y / (double)delta_x;
                    if (myhash.find(slope) == myhash.end()) {
                        myhash[slope] = 2;
                        max_hash = max(max_hash, myhash[slope]);
                    } else {
                        myhash[slope] = myhash[slope] + 1;
                        max_hash = max(max_hash, myhash[slope]);
                    }
                }
            }
            max_value = max(max_value, max(vertical, max_hash) + same_point) ;

        }
        return max_value;
    }
};
