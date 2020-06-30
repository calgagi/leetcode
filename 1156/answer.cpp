class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char,int> s;
        for (char c : text) s[c]++;
        int r = 0;
        for (pair<char,int> c : s) {
            int current = 0, prev = 0;
            for (char i : text) {
                if (i == c.first && c.second > 0) {
                    current++;
                    c.second--;
                } else {
                    if (c.second > 0) {
                        current++;
                        current -= prev;
                        c.second += prev-1;
                        prev = current;
                    } else {
                        current = 0;
                        prev = 0;
                    }
                }
                r = max(r, current);
            }
        }
        return r;
    }
};
