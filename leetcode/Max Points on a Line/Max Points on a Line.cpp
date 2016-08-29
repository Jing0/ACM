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
        int size = points.size();
        if (!size) {
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            map<float, int> m;
            int max = 0;
            int vnt = 1;
            int dnt = 0;
            for (int j = i + 1; j < size; ++j) {
                Point p1 = points.at(i);
                Point p2 = points.at(j);
                if (p1.x == p2.x && p1.y == p2.y) {
                    dnt++;
                    vnt++;
                } else if (p1.x == p2.x) {
                    vnt++;
                } else {
                    float k = ((float)p1.y - p2.y)/(p1.x - p2.x);
                    m[k]++;
                    if (max < m[k] + 1) {
                        max = m[k] + 1;
                    }
                }
            }
            if (vnt > ans) {
                ans = vnt;
            }
            if (max + dnt > ans) {
                ans = max + dnt;
            }
        }
        return ans;
    }
};
