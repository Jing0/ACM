class Solution {
public:
    int longestPalindrome(string s) {
        int ascii[128] = {0};
        int ones = 0, twos = 0;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            ascii[s.at(i)]++;
            if (ascii[s.at(i)] == 1) {
                ones++;
            } else if (ascii[s.at(i)] == 2) {
                twos++;
                ones--;
                ascii[s.at(i)] = 0;
            }
        }
        return twos * 2 + (ones > 0);
    }
};
