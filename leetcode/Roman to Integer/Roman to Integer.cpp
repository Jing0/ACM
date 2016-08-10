class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int length = s.length();
        for (int i = 0; i < length; ++i) {
            if (i && getCharVal(s.at(i)) > getCharVal(s.at(i - 1))) {
                ans += getCharVal(s.at(i)) - 2 * getCharVal(s.at(i - 1));             
            } else {
                ans += getCharVal(s.at(i));
            }
        }
        return ans;
    }
private:
    int getCharVal(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
};
