class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int lo = 0, hi = x / 2 + 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int t = x / mid;
            if (t == mid || (mid < x / mid && (mid + 1) > x / (mid + 1))) {
                return mid;
            } else if (t > mid) {
                lo = mid + 1;
            } else if (t < mid) {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
