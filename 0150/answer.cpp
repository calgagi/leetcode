class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string& c : tokens) {
            if (c == "+") {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                s.push(x + y);
            } else if (c == "-") {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                s.push(x - y);
            } else if (c == "*") {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                s.push(x * y);
            } else if (c == "/") {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                s.push(x / y);
            } else {
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};
