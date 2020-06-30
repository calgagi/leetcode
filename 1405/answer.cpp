class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        vector<pair<int,char>> l = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (true) {
            sort(l.rbegin(), l.rend());
            if (l[0].first) {
                res += l[0].second;
                l[0].first--;
            } else {
                break;
            }
            bool f = 0;
            for (int i = 1; i < 3; i++) {
                if (l[i].first) {
                    res += l[i].second;
                    l[i].first--;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                break;
            }
        }
        sort(l.rbegin(), l.rend());
        for (int i = 0; l[0].first && i < (int) res.length(); i++) {
            if (l[0].second == res[i]) {
                res.insert(res.begin()+i, l[0].second);
                i++;
                l[0].first--;
            }
        }
        return res;
    }
};
