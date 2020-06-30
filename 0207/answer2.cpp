class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < (int) prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> counts(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (int v : graph[i]) {
                counts[v]++;
            }
        }
        
        vector<int> fringe;
        for (int i = 0; i < numCourses; i++) {
            if (counts[i] == 0) {
                fringe.push_back(i);
            }
        }
        
        int ans = 0;
        while (!fringe.empty()) {
            vector<int> new_fringe;
            for (int i = 0; i < (int) fringe.size(); i++) {
                for (int v : graph[fringe[i]]) {   
                    counts[v]--;
                    if (counts[v] == 0) {
                        new_fringe.push_back(v);
                    }
                }
                
            }
            ans += fringe.size();
            fringe = new_fringe;
        }
        
        return ans == numCourses;
    }
};
