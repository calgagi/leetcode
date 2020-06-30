class Solution {
public:
    vector<int> lexicalOrder(int n) {
        stack<int> s;
        vector<int> r;
        s.push(1);
        while (!s.empty()) {
            int x = s.top();
            s.pop();
            r.push_back(x);
            if (x + 1 <= n && (x % 10) != 9) s.push(x+1);
            if (x * 10 <= n) s.push(x*10);
        }
        return r;
    }
};
