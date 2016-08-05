class Solution {
public:
    int addDigits(int num) {
        int ans = num % 9;
        return num ? (ans ? ans : 9): 0;
    }
};
