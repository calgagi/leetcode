class FreqStack {
public:
    unordered_map<int, stack<int>> sts;
    int maxFreq;
    unordered_map<int, int> freq;
    
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int x) {
        freq[x]++;
        maxFreq = max(freq[x], maxFreq);
        sts[freq[x]].push(x);
    }
    
    int pop() {
        if (sts[maxFreq].empty())
            maxFreq--;
        int res = sts[maxFreq].top();
        freq[res]--;
        sts[maxFreq].pop();
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
