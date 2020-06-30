class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, vector<char>> counts;
        unordered_map<char, int> seen;
        int m = 0;
        for (int i = 0; i < s.size(); i++) {
            seen[s[i]]++;
            m = max(seen[s[i]], m);
            counts[seen[s[i]]].push_back(s[i]);
            for (auto it = counts[seen[s[i]]-1].begin(); it != counts[seen[s[i]]-1].end(); ++it) {
                if (*it == s[i]) { counts[seen[s[i]]-1].erase(it); it--; }
            }
            
        }
        int a = 0;
        for (int i = m; i >= 1; i--) {
            for (int j = 0; j < counts[i].size(); j++) {
                for (int k = 0; k < i; k++) {
                    s[a] = counts[i][j];
                    a++;
                }
            }
        }
        return s;
    }
};
