class MinStack {
private:
    stack<long long> s;
    long long mini;

public:
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            mini = val;
        } else {
            if (val < mini) {
                s.push(2LL * val - mini);
                mini = val;
            } else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.empty()) return;

        long long x = s.top();
        s.pop();

        if (x < mini)
            mini = 2 * mini - x;
    }

    int top() {
        if (s.top() < mini)
            return mini;
        return s.top();
    }

    int getMin() {
        return mini;
    }
};