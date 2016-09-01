class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int size = strs.size();
        if (!size) {
            return ans;
        }
        bool common = true;
        int len = 0;
        while (common) {
            char c;
            for (int i = 0; i < size; ++i) {
                string tmp = strs.at(i);
                int tmplen = tmp.length();
                if (len >= tmplen) {
                    common = false;
                } else if (!i) {
                    c = tmp.at(len);
                } else {
                    if (c != tmp.at(len)) {
                        common = false;
                    }
                }
            }
            if (common) {
                ans = ans + c;
                len++;
            }
        }
        return ans;
    }
};
