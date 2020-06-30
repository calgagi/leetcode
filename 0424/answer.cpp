class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0;
        for (char c = 'A'; c <= 'Z'; c++) {
            int m = 0, x = 0, y = 1;
            queue<int> q;
            for (int i = 0; i < s.length(); i++) {
                if (c != s[i]) {
                    if (!q.empty() && q.size() == k) {
                        x -= q.front();
                        q.pop();
                    }
                    if (k) {
                        q.push(y);
                        x++;
                    } else 
                        x = 0;
                    y = 1;
                } else {
                    y++;
                    x++;
                }
                m = max(m, x);
            }
            r = max(m, r);
        }
        return r;
    }
};
