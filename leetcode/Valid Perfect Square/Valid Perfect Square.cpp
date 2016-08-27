class Solution {
public:
    bool isPerfectSquare(int num) {
        if (!num) {
            return false;
        }
        if (num == 1) {
            return true;
        }
        int lo = 0, hi = num / 2;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            long s = (long)mid * mid;
            if (s > num) {
                hi = mid - 1;
            } else if (s < num) {
                lo = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
