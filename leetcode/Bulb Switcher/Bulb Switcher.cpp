class Solution {
public:
    int bulbSwitch(int n) {
        int i = 0;
        while ((int)pow(i, 2) <= n) {
            ++i;
        }
        return i - 1;
    }
};
