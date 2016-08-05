class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;
        int carry = 0;
        for (int i = 0; i < 32; ++i) {
            int bita = a & (1<<i);
            int bitb = b & (1<<i);
            if (bita && bitb && carry ) {
                ans |= (1<<i);
                carry = 1;
            } else if ((!bita && !bitb && carry) || (!bita && bitb && !carry) || (bita && !bitb && !carry)) {
                ans |= (1<<i);
                carry = 0;
            } else if ((bita && bitb && !carry) || (bita && !bitb && carry) || (!bita && bitb && carry)) {
                carry = 1;
            }
        }
        return ans;
    }
};

