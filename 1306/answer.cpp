class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // BFS
        const int n = arr.size();
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int s = q.front(); q.pop();
            if (visited.find(s) != visited.end()) continue;
            visited.insert(s);
            if (arr[s] == 0) return true;
            if (s+arr[s] < n) {
                q.push(s+arr[s]);
            }
            if (s-arr[s] >= 0) {
                q.push(s-arr[s]);
            }
        }
        return false;
    }
};
