class Solution {
public:
    int firstUniqChar(string s) {
        int letterpos[26];
        int lettercnt[26];
        for (int i = 0; i < 26; ++i) {
            letterpos[i] = -1;
            lettercnt[i] = 0;
        }
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            int c = s.at(i) - 'a';
            if (letterpos[c] == -1) {
                letterpos[c] = i;
            }
            lettercnt[c]++;
        }
        int ans = len;
        for (int i = 0; i < 26; ++i) {
            if (letterpos[i] != -1 && lettercnt[i] == 1) {
                if (letterpos[i] < ans) {
                    ans = letterpos[i];
                }
            }
        }
        return ans == len ? -1 : ans;
    }
};
