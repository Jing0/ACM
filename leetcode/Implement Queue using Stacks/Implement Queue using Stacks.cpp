class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        st.push(x);
        size++;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> tmp;
        for (int i = 0; i < size - 1; ++i) {
            tmp.push(st.top());
            st.pop();
        }
        st.pop();
        for (int i = 0; i < size - 1; ++i) {
            st.push(tmp.top());
            tmp.pop();
        }
        size--;
    }

    // Get the front element.
    int peek(void) {
        stack<int> tmp;
        for (int i = 0; i < size - 1; ++i) {
            tmp.push(st.top());
            st.pop();
        }
        int ans = st.top();
        for (int i = 0; i < size - 1; ++i) {
            st.push(tmp.top());
            tmp.pop();
        }
        return ans;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return size == 0;
    }
private:
    stack<int> st;
    int size = 0;
};
