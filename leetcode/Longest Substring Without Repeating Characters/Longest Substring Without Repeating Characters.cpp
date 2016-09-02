class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int charLimit = 257;
        int a[charLimit];
        int len = s.length();
        for (int i = 0; i < charLimit; ++i) {
            a[i] = -1;
        }
        int max = 0, count = 0;
        for (int i = 0; i < len; ++i) {
            int c = (int)s.at(i);
            if (a[c] == -1) {
                a[c] = i;
                count++;
            } else {
                if (count > max) {
                    max = count;
                }
                for (int j = i - count; j < a[c]; ++j) {
                    a[(int)s.at(j)] = -1;
                }
                count = i - a[c];
                a[c] = i;
            }
        }
        if (count > max) {
            max = count;
        }
        return max;
    }
};
