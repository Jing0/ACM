class Solution {
public:
    bool isAnagram(string s, string t) {
        int lens = s.length();
        int lent = t.length();
        if (lens != lent) {
            return false;
        }
        char *cs = (char *)malloc(sizeof(char) * lens);
        char *ct = (char *)malloc(sizeof(char) * lent);
        strcpy(cs, s.c_str());
        strcpy(ct, t.c_str());
        sort(cs, cs + lens, [](char a, char b) {
            return a > b;
        });
        sort(ct, ct + lent, [](char a, char b) {
            return a > b;
        });
        return strcmp(cs, ct) == 0 ? true:false;
    }
};
