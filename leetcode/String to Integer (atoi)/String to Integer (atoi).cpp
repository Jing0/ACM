class Solution {
public:
    int myAtoi(string str) {
        int length = str.length();
        long ans = 0;
        if (!length) {
            return ans;
        }
        int begin = 0;
        while (begin < length && str.at(begin) == ' ') {
            begin++;
        }
        if (begin == length) {
            return ans;
        }
        char ch = str.at(begin);
        int sign = (ch == '-') ? 1 : 0;
        begin += (ch == '-' || ch == '+') ? 1 : 0;
        for (int i = begin; i < length; ++i) {
            ch = str.at(i);
            if (ch  < '0' || ch > '9') {
                break;
            }
            ans = ans * 10 + ch - '0';
            if (ans > (long)INT_MAX + 1) {
                break;
            }
        }
        if (sign) {
            ans = -ans;
        }
        if (ans > INT_MAX) {
            ans = INT_MAX;
        } else if (ans < INT_MIN) {
            ans = INT_MIN;
        }
        return ans;
    }
};
