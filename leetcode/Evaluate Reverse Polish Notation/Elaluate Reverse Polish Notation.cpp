class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int size = tokens.size();
        for (int i = 0; i < size; ++i) {
            string str = tokens.at(i);
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if (str == "+") {
                    st.push(a + b);
                } else if (str == "-") {
                    st.push(a - b);
                } else if (str == "*") {
                    st.push(a * b);
                } else if (str == "/") {
                    st.push(a / b);
                }
            } else {
                st.push(stoi(tokens.at(i)));
            }
        }
        return st.top();
    }
};
