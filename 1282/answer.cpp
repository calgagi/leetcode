class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> graph;
        for (int i = 0; i < groupSizes.size(); i++) {
            graph[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> res;
        for (auto& it : graph) {
            vector<int> group;
            for (int i = 0; i < it.second.size(); i++) {
                if (i != 0 && i % it.first == 0) {
                    res.push_back(group);
                    group.clear();
                }
                group.push_back(it.second[i]);
            }
            res.push_back(group);
        }
        return res;
    }
};
