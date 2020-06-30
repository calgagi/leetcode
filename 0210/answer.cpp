class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<pair<int,vector<int>>> graph(numCourses, {0, vector<int>()});
        for (auto& p : prerequisites) {
            graph[p[1]].second.push_back(p[0]);
            graph[p[0]].first++;
        }
        // Kahn's
        vector<int> res, fringe;
        for (int i = 0; i < numCourses; i++)
            if (graph[i].first == 0)
                fringe.push_back(i);
        vector<bool> seen(numCourses);
        while (!fringe.empty()) {
            vector<int> new_fringe;
            for (auto& item : fringe) {
                if (seen[item]) return vector<int>();
                for (auto& edge : graph[item].second) {
                    graph[edge].first--;
                    if (graph[edge].first == 0)
                        new_fringe.push_back(edge);
                }
                res.push_back(item);
                seen[item] = true;
            }
            fringe = new_fringe;
        }
        return (res.size() == numCourses ? res : vector<int>());
    }
};
