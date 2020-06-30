class Solution {
public:
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<bool> seen((int) friends.size(), false);
        vector<int> fringe(1);
        fringe[0] = id;
        seen[id] = true;
        for (int i = 0; i < level; i++) {
            vector<int> new_fringe;
            for (auto& f : fringe) {
                for (auto& j : friends[f]) {
                    if (!seen[j]) {
                        new_fringe.push_back(j);
                        seen[j] = true;
                    }
                }
            }
            fringe = new_fringe;
        }
        
        unordered_map<string, int> m;
        for (auto& person : fringe) {
            for (int i = 0; i < (int) watchedVideos[person].size(); i++) {
                m[watchedVideos[person][i]]++;
            }
        }
        vector<pair<int, string>> res;
        for (auto& p : m) {
            res.push_back({p.second, p.first});
        }
        sort(res.begin(), res.end());
        vector<string> new_res;
        for (auto& p : res) {
            new_res.push_back(p.second);
        }
        return new_res;
    }
};
