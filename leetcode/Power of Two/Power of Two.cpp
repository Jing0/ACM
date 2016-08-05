class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (!n) {
            return false;
        }
        while ((n & 1) == 0) {
            n >>= 1;
        }
        if ((n ^ 1) != 0) {
            return false;
        }
        return true;
    }
};
