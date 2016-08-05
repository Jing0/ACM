class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if (len == 0) {
            return true;
        }
        
        char *newstr = (char *)malloc(sizeof(char) * len + 1);
        strcpy(newstr, s.c_str());
        int newlen = 0;
        for (int i = 0; i < len; ++i) {
            char c = s.at(i);
            if ((c >= 'a' && c <= 'z') || (c >='0' && c <='9')) {
                newstr[newlen++] = c;
            } else if (c >= 'A' && c <= 'Z') {
                newstr[newlen++] = c - 'A' + 'a';
            }
        }
        for (int i = 0; i < newlen; ++i) {
            if (newstr[i] != newstr[newlen - 1 -i]) {
                return false;
            }
        }
        return true;
    }
};
