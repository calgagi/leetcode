class Solution {
public:
    vector<vector<int>> fenwick;
    int n;
    
    void update(int i, int j) {
        for (; j < n; j = (j | (j + 1))) {
            fenwick[i][j]++;
        }
        return;
    }
    
    int get_sum(int i, int j) {
        int ans = 0;
        for (; j >= 0; j = (j & (j + 1)) - 1) {
            ans += fenwick[i][j];
        }
        return ans;
    }
    
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> start(26, -1), end(26, -1);
        n = s.length();
        fenwick.assign(26, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            if (start[s[i] - 'a'] == -1) {
                start[s[i] - 'a'] = i;
            }
            end[s[i] - 'a'] = i;
            update(s[i] - 'a', i);
        }
        
        vector<pair<int,int>> strs;
        for (int i = 0; i < 26; i++) {
            if (start[i] == -1) {
                continue;
            }
            int s = start[i], e = end[i];
            vector<bool> used(26, 0);
            used[i] = 1;
            for (int k = 0; k < 26; k++) {
                if (start[k] == -1 || used[k]) {
                    continue;
                }
                if (get_sum(k, e) - get_sum(k, s)) {
                    used[k] = 1;
                    s = min(s, start[k]);
                    e = max(e, end[k]);
                    k = -1;
                }
            }
            strs.push_back({s, e - s + 1});
        }
        
        sort(strs.begin(), strs.end(), greater<pair<int,int>>());
        
        vector<string> ans;
        int mn = n;
        for (pair<int,int>& str : strs) {
            if (ans.empty() || str.first + str.second - 1 < mn) {
                ans.push_back(s.substr(str.first, str.second));
                mn = str.first;
            }
        }
        return ans;
    }
};
