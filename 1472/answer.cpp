class BrowserHistory {
public:
    vector<string> s;
    int i;
    
    BrowserHistory(string homepage) {
        s.push_back(homepage);
        i = 0;
    }
    
    void visit(string url) {
        if (i < s.size()-1) {
            s.erase(s.begin()+i+1, s.end());
        }
        s.push_back(url);
        i++;
        return;
    }
    
    string back(int steps) {
        i = max(0, i-steps);
        return s[i];
    }
    
    string forward(int steps) {
        i = min(i+steps, (int) s.size()-1);
        return s[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
