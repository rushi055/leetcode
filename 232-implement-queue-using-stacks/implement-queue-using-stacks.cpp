class MyQueue {
public:
    stack<int> S1;
    stack<int> S2;

    void transfer() {
        while (!S1.empty()) {
            S2.push(S1.top());
            S1.pop();
        }
    }
    MyQueue() {}

    void push(int x) { S1.push(x); }

    int pop() {
        if (S2.empty()) {
            transfer();
        }
        int frontElement = S2.top();
        S2.pop();
        return frontElement;
    }

    int peek() {
        if (S2.empty()) {
            transfer();
        }
        return S2.top();
    }

    bool empty() { return S1.empty() && S2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */