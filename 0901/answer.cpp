class StockSpanner {
public:
    
    stack<pair<int,int>> s;
    int i; 
    
    StockSpanner() { 
        i = 0;
    }
    
    int next(int price) {
        i += 1;
        int p = i;
        while (s.size() && s.top().first <= price) {
            p = s.top().second;
            s.pop();
        }
        s.push({price, p});
        return i-p+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
