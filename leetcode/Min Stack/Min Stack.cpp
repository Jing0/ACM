class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        initMin();
    }
    
    void push(int x) {
        if (x <= min) {
            mins.push(x);
            min = x;
        }
        st.push(x);
    }
    
    void pop() {
        if (mins.top() == st.top()) {
            mins.pop();
            if (mins.empty()) {
                initMin();
            } else {
                min = mins.top();
            }
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    stack<int> st;
    stack<int> mins;
    int min;
    void initMin() {
        min = 0;
        for (int i = 0; i < 31; ++i) {
            min <<= 1;
            min |= 1;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
