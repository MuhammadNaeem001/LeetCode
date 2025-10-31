class MyQueue {
    stack<int> in, out;
public:
    void push(int x) { in.push(x); }
    
    int pop() {
        int val = peek();
        out.pop();
        return val;
    }
    
    int peek() {
        if (out.empty())
            while (!in.empty()) { out.push(in.top()); in.pop(); }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();
    }
};
