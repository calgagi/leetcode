class Solution {
public:    
    int scoreOfParentheses(string S) {
        int r = 0;
        stack<int> s;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                s.push(r);
                r = 0;
            } else {
                r += s.top() + max(1, r);
                s.pop();
            }
        }
        return r;
    }
};
