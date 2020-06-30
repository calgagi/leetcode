class Solution {
public:    
    int get_num(const string& s, int& i) {
        string r;
        for (; i < s.length() && s[i] >= '0' && s[i] <= '9'; i++) {
            r += s[i];
        }
        return stoi(r);
    }
    
    int apply_op(int a, int b, char op) {
        if (op == '+') {
            return a + b;
        } else if (op == '-') {
            return a - b;
        } else if (op == '*') {
            return a * b;
        }
        return -1;
    }
    
    vector<int> helper(vector<int> n, vector<char> ops) {
        if (n.size() <= 1 || ops.size() == 0) {
            return n;
        }
        vector<int> left_nums, right_nums = n;
        vector<char> left_ops, right_ops = ops;

        vector<int> res;
        for (int i = 0; i < ops.size(); i++) {
            right_nums.erase(right_nums.begin());
            left_nums.push_back(n[i]);
            right_ops.erase(right_ops.begin());
            if (i) {
                left_ops.push_back(ops[i-1]);
            }
            vector<int> left = helper(left_nums, left_ops);
            vector<int> right = helper(right_nums, right_ops);
            for (auto& l : left) {
                for (auto& r : right) {
                    res.push_back(apply_op(l, r, ops[i]));
                }
            }
        }
        return res;
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> numbers;
        vector<char> ops;
        for (int i = 0; i < input.length(); i++) {
            numbers.push_back(get_num(input, i));
            if (i < input.length()) {
                ops.push_back(input[i]);
            }
        }
        
        /*for (auto& i : numbers) {
            cout << i << " ";
        }
        cout << endl;
        for (auto& c : ops) {
            cout << c << " ";
        }
        cout << endl;*/
        
        vector<int> res = helper(numbers, ops);
        
        return res;
    }
};
