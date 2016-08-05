class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            char c = s.at(i);
            if (st.empty()) {
                if (c == ')' || c == ']' || c == '}') {
                    return false;
                }
                st.push(c);
            } else if (match(st.top(), c)) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        if (st.size()) {
            return false;
        }
        return true;
    }
private:
    bool match(char a, char b) {
        if ((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) {
            return true;
        }
        return false;
    }
};
