class Solution {
public:
    void get_union(unordered_set<string>& res, unordered_set<string>& x) {
        for (auto &item : x) {
            res.insert(item);
        }
    }
    
    void get_concat(unordered_set<string>& res, unordered_set<string>& x) {
        if (x.size() == 0) return;
        if (res.size()) {
            unordered_set<string> new_res;
            for (auto &item : res) {
                for (auto &item_x : x) {
                    new_res.insert(item + item_x);
                }
            }
            res = new_res;
        } else {
            res = x;
        }
    }
    
    unordered_set<string> get_set(string const& expression, int& i) {
        unordered_set<string> res;
        unordered_set<string> current;
        string c = "";
        while (i < expression.length() && expression[i] != '}') {
            if (expression[i] == '{') {
                if (c != "") {
                    unordered_set<string> d = {c};
                    get_concat(current, d);
                }
                c = "";
                i++;
                unordered_set<string> inner_set = get_set(expression, i);
                get_concat(current, inner_set);
            } else if (expression[i] == ',') {
                if (c != "") {
                    unordered_set<string> d = {c};
                    get_concat(current, d);
                }
                c = "";
                get_union(res, current);
                current.clear();
            } else {
                c += expression[i];
            }
            i++;
        }
        if (c != "") {
            unordered_set<string> d = {c};
            get_concat(current, d);
        }
        get_union(res, current);
        return res;
    }
    
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        unordered_set<string> s = get_set(expression, i);
        vector<string> res(s.begin(), s.end());
        sort(res.begin(), res.end());
        return res;
    }
};
