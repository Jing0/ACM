class Solution {
public:
    int reverse(int x) {
        int sign = x < 0 ? 1 : 0;
        int ans = 0;
        while (x) {
            long t = (long)ans * 10 + x % 10;
            if (t > INT_MAX || t < INT_MIN) {
                return 0;
            }
            ans = t;
            x /= 10;
        }
        return ans;
    }
};
