class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int length = path.length();
        int i = 0;
        while (i < length) {
            string t;
            if (path.at(i) == '/') {
                int j = 1;
                while (i + j < length && path.at(i + j) != '/') {
                    ++j;
                }
                t = path.substr(i, j);
                i += j;
            }
            if (t == "/." || t == "/") {
                ;
            } else if (t == "/..") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(t);
            }
        }
        while (st.size() > 1 && st.top() == "/") {
            st.pop();
        }
        string ans;
        if (st.empty()) {
            ans = "/";
        } else {
            while (!st.empty()) {
                ans = st.top() + ans;
                st.pop();
            }
        }
        return ans;
    }
};
