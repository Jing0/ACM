class Solution {
public:
    string convertToTitle(int n) {
        list<int> li;
        while (n) {
            int t = n % 26;
            if (!t) {
                t = 26;
                n -= 26;
            }
            li.push_back(t - 1 + 'A');
            n /= 26;
        }
        char *cstr = (char *)malloc(sizeof(char) * li.size() + 1);
        int i;
        for (i = 0; !li.empty(); ++i) {
            cstr[i] = li.back();
            li.pop_back();
        }
        cstr[i] = '\0';
        string s(cstr);
        return s;
    }
};
