class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        int len = max(len1, len2) + 1;
        string ans(len, '0');
        int i = 0, carry = 0;
        while (i < len1 && i < len2) {
            int tmp = num1.at(len1 - 1 - i) + num2.at(len2 - 1 - i) - 2 * '0' + carry;
            carry = tmp > 9;
            ans.at(len - 1 - i) = tmp % 10 + '0';
            ++i;
        }
        while (i < len1) {
            int tmp = num1.at(len1 - 1 - i) - '0' + carry;
            carry = tmp > 9;
            ans.at(len - 1 - i) = tmp % 10 + '0';
            ++i;
        }
        while (i < len2) {
            int tmp = num2.at(len2 - 1 - i) - '0' + carry;
            carry = tmp > 9;
            ans.at(len - 1 - i) = tmp % 10 + '0';
            ++i;
        }
        if (carry) {
            ans.at(len - 1 - i) = '1';
            ++i;
        }
        return ans.substr(len - i);
    }
};
