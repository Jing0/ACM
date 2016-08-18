class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string ans;
        int length = s.length();
        for (int i = 0; i < numRows; ++i) {
            if (!i || (i == numRows - 1)) {
                int j = i;
                while (j < length) {
                    ans = ans + s.at(j);
                    j += 2 * numRows - 2;
                }
            } else {
                bool trans = true;
                for (int j = i; j < length; ) {
                    ans = ans + s.at(j);
                    if (trans) {
                        j += 2 * (numRows - i - 1);
                    } else {
                        j += 2 * i;
                    }
                    trans = !trans;
                }
            }
        }
        return ans;
    }
};
