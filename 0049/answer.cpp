class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<string,int>> d(n);
        for (int i = 0; i < n; i++) {
            d[i] = {strs[i], i};
            sort(d[i].first.begin(), d[i].first.end());
        }
        sort(d.begin(), d.end());
        vector<vector<string>> ans;
        for (int i = 0; i < n; ) {
            string x = d[i].first;
            ans.push_back(vector<string>());
            while (i < n && x == d[i].first) {
                ans.back().push_back(strs[d[i].second]);
                i++;
            }
        }
        return ans;
    }
};
