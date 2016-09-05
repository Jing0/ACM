class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        bool table[1000][1000] = {false};
        for (int i = 0; i < len; ++i) {
            table[i][i] = true;
        }
        int begin = 0;
        int maxlen = 1;
        for (int i = 0; i < len - 1; ++i) {
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                begin = i;
                maxlen = 2;
            }
        }
        for (int l = 3; l <= len; ++l) {
            for (int i = 0; i < len + 1 - l; ++i) {
                int j = i + l - 1;
                if (s[i] == s[j] && table[i + 1][j - 1]) {
                    maxlen = l;
                    begin = i;
                    table[i][j] = true;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};
