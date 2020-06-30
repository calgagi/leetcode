class CustomStack {
public:
    int ms;
    stack<int> st;
    vector<int> pre;
    
    CustomStack(int maxSize) {
        ms = maxSize;
        pre.assign(ms+1, 0);
    }
    
    void push(int x) {
        if (st.size() < ms) {
            st.push(x);
        }
        return;
    }
    
    int pop() {
        if (st.empty()) {
            return -1;
        }
        int res = st.top();
        int tot = 0;
        for (int i = ms; i >= st.size(); i--) {
            tot += pre[i];
            pre[i] = 0;
        }
        st.pop();
        pre[st.size()] += tot;
        return res+tot;
    }
    
    void increment(int k, int val) {
        k = min(k, (int) st.size());
        pre[k] += val;
        /*for (int i = 0; i < ms; i++) {
            cout << pre[i] << " ";
        }
        cout << endl;*/
        pre[0] = 0;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
