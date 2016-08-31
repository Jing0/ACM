class Solution {
public:
    string countAndSay(int n) {
        if (!n) {
            return "1";
        }
        string ans = "1";
        while (--n) {
            string tmp;
            int length = ans.length();
            for (int i = 0; i < length; ++i) {
                int j;
                for (j = 1; i + j < length && ans.at(i + j) == ans.at(i); ++j) {
                    ;
                }
                tmp.append(itos(j));
                tmp = tmp + ans.at(i);
                i += j - 1;
            }
            ans = tmp;
        }
        return ans;
    }
private:
    string itos(int n) {
        string ans;
        while (n) {
            ans = (char)(n % 10 + '0') + ans;
            n /= 10;
        }
        return ans;
    }
};
