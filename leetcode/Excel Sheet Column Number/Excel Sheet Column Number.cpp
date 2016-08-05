class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        char *cstr = (char *)malloc(sizeof(char) * len + 1);
        strcpy(cstr, s.c_str());
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            ans = ans * 26 + cstr[i] - 'A' + 1;
        }
        return ans;
    }
};
