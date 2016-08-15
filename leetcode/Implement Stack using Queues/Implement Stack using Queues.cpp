class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
        size++;
    }

    // Removes the element on top of the stack.
    void pop() {
        for (int i = 0; i < size - 1; ++i) {
            que.push(que.front());
            que.pop();
        }
        que.pop();
        size--;
    }

    // Get the top element.
    int top() {
        for (int i = 0; i < size - 1; ++i) {
            que.push(que.front());
            que.pop();
        }
        int ans = que.front();
        que.push(ans);
        que.pop();
        return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return size == 0;
    }
private:
    queue<int> que;
    int size = 0;
};
