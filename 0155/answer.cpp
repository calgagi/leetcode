class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> m1, m2;
    
    MinStack() {
        
    }
    
    void push(int x) {
        m1.push(x);
        if (m2.empty() || m2.top() >= x) {
            m2.push(x);
        }
    }
    
    void pop() {
        int a = m1.top();
        m1.pop();
        if (m2.top() == a) {
            m2.pop();
        }
    }
    
    int top() {
        return m1.top();
    }
    
    int getMin() {
        return m2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
