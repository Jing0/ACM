class Solution {
public:
    string reverseVowels(string s) {
        stack<int> st;
        int len = s.length();
        const string vowels = "aeiouAEIOU";
        for (int i = 0; i < len; ++i) {
            char c = s.at(i);
            if (vowels.find(c) != -1) {
                st.push(c);
            }
        }
        string ans;
        for (int  i = 0; i < len; ++i) {
            char c = s.at(i);
            if (vowels.find(c) != -1) {
                c = st.top();
                st.pop();
            }
            ans = ans + string(1, c);
        }
        return ans;
    }
};
