class Solution {
public:
    unordered_map<string, vector<string>> master;
    string ans = "";
    
    pair<bool,bool> dfs(string c) {
        pair<bool,bool> res = {false, false};
        if (region1 == c) res.first = true;
        if (region2 == c) res.second = true;
        for(auto& s : master[c]) {
            auto r = dfs(s);
            res.first = res.first || r.first;
            res.second = res.second || r.second;
            if (res.first && res.second && ans == "") {
                ans = c;
                return res;
            }
        }
        return res;
    }
    
    string region1, region2;
    
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        this->region1 = region1;
        this->region2 = region2;
        
        for(auto& r : regions) {
            string big = r[0];
            for(int i = 1; i < r.size(); i++) {
                master[big].push_back(r[i]);
            }
        }
        
        // Find head
        string head = master.begin()->first;
        unordered_map<string,int> connect;
        for(auto it = master.begin(); it != master.end(); it++) {
            for(auto& i : it->second)
                connect[i]++;
        }
        for(auto it = master.begin(); it != master.end(); it++)
            if (connect[it->first] == 0) {
                head = it->first;
                break;
            }
        dfs(head);
        return ans;
    }
};
