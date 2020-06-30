class FreqStack {
public:
    struct Node {
        Node* next;
        int val;
        Node(int v) {val = v;}
    };
    
    unordered_map<int, int> c;
    int maxFreq;
    unordered_map<int, int> freq;
    Node* head;
    
    FreqStack() {
        head = NULL;
        maxFreq = 0;
    }
    
    void push(int x) {
        freq[c[x]]--;
        c[x]++;
        freq[c[x]]++;
        maxFreq = max(maxFreq, c[x]);
        Node* temp = head;
        head = new Node(x);
        head->next = temp;
    }
    
    int pop() {
        Node* it = head, * prev = NULL;
        while (it && it->next != NULL && maxFreq != c[it->val]) {
            prev = it;
            it = it->next;
        }
        c[it->val]--;
        int res = it->val;
        freq[maxFreq]--;
        freq[maxFreq-1]++;
        if (freq[maxFreq] == 0)
            maxFreq--;
        if (prev == NULL)
            head = head->next;
        else
            prev->next = it->next;
        if (it) delete it;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
