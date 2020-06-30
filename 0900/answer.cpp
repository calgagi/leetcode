class RLEIterator {
public:

    int i;
    vector<int> x;
    
    RLEIterator(vector<int>& A) {
        i = 0;
        x = A;
    }
    
    int next(int n) {
        if (i >= x.size()-1) 
            return -1;
        while (n != 0 && i+1 < x.size()) {
            if (x[i] < n) {
                n -= x[i];
                i += 2;
            } else {
                x[i] -= n;
                n = 0;
            } 
        }
        if (i >= x.size()-1)
            return -1;
        else
            return x[i+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
