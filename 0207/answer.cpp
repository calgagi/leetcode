class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // BFS problem
        unordered_map<int, vector<int>> g;
        int has_prereq[numCourses];
        memset(has_prereq, 0, sizeof(int)*numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            g[prerequisites[i][1]].push_back(prerequisites[i][0]);
            has_prereq[prerequisites[i][0]]++;
        }
        set<int> x;
        for (int i = 0; i < numCourses; i++) {
            // If no prereqs
            if (!has_prereq[i] && x.find(i) == x.end()) {
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    if (x.find(t) != x.end())
                        continue;
                    x.insert(t);
                    if (x.size() == numCourses) return true;
                    for (auto b : g[t]) {
                        has_prereq[b]--;
                        if (!has_prereq[b])
                            q.push(b);
                    }
                }
            }
        }
        return false;
    }
};
