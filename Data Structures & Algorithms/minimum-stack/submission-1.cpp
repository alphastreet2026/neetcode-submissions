class MinStack {
    stack<int> elements;
    stack<int> mins;

   public:
    MinStack() {}

    void push(int val) {
        elements.push(val);
        if (mins.empty()) {
            mins.push(val);
            return;
        }
        if (mins.top() < val) {
            mins.push(mins.top());
        } else {
            mins.push(val);
        }
    }

    void pop() {
        elements.pop();
        mins.pop();
    }

    int top() { return elements.top(); }

    int getMin() {
        return mins.top();
    }
};
