class Solution {
public:
    
    
    bool parseBoolExpr(string expression) {
        stack<char> s;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '!' || expression[i] == '&' || expression[i] == '|' || expression[i] == 't' || expression[i] == 'f') {
                s.push(expression[i]);
            } else if (expression[i] == ')') {
                vector<bool> in;
                while ((s.top() == 't') || (s.top() == 'f')) {
                    in.push_back((s.top() == 'f' ? false : true));
                    s.pop();
                }
                char op = s.top(); s.pop();
                bool result;
                switch (op) {
                    case '&': {
                        result = true;
                        for (auto b : in) result = result && b;
                        break;
                    }
                    case '|': {
                        result = false;
                        for (auto b : in) result = result || b;
                        break;
                    }
                    case '!': {
                        result = !in[0];
                        break;
                    }
                }
                s.push((result ? 't' : 'f'));
            }
        }
        return s.top() == 't';
    }
};
