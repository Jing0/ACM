class Solution {
public:
    int climbStairs(int n) {
        int a = 0;
        int b = 1;
        while (n--) {
            int t = b;
            b += a;
            a = t;
        }
        return b;
    }
};
