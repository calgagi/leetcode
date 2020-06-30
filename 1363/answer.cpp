class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end(), greater<int>());
        int s = 0, n = digits.size();
        vector<int> z, o, t;
        for (int i = 0; i < n; i++) {
            s += digits[i];
            if (digits[i] % 3 == 0) {
                z.push_back(digits[i]);
            } else if (digits[i] % 3 == 1) {
                o.push_back(digits[i]);
            } else if (digits[i] % 3 == 2) {
                t.push_back(digits[i]);
            }
        }
        if (s % 3 == 1) {
            if (o.size() >= 1) {
                o.pop_back();
            } else if (t.size() >= 2) {
                t.pop_back();
                t.pop_back();
            } else {
                return "";
            }
        } else if (s % 3 == 2) {
            if (t.size() >= 1) {
                t.pop_back();
            } else if (o.size() >= 2) {
                o.pop_back();
                o.pop_back();
            } else {
                return "";
            }
        }
        for (auto i : o) {
            z.push_back(i);
        } 
        for (auto i : t) {
            z.push_back(i);
        }
        sort(z.begin(), z.end(), greater<int>());
        string r = "";
        for (int i = 0; i < z.size(); i++) {
            r += (char) (z[i] + '0');
        }
        if (!r.empty() && r[0] == '0') {
            return "0";
        }
        return r;
    }
};
