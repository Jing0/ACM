class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.length();
        int lenb = b.length();
        if (lena > lenb) {
            swap(lena, lenb);
            swap(a, b);
        }
        string ans;
        int carry = 0;
        int i;
        for (i = 0; i < lenb; ++i) {
            int sum;
            if (i < lena) {
                sum = carry + a.at(lena - 1 - i) + b.at(lenb - 1 - i) - '0' * 2;
            } else {
                sum = carry + b.at(lenb - 1 - i) - '0';
            }
            if (sum == 0) {
                carry = 0;
                ans = "0" + ans;
            } else if (sum == 1) {
                carry = 0;
                ans = "1" + ans;
            } else if (sum == 2) {
                carry = 1;
                ans = "0" + ans;
            } else if (sum == 3) {
                carry = 1;
                ans = "1" + ans;
            }
        }
        if (carry) {
            ans = "1" + ans;
        }
        return ans;
    }
};
