class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,vector<int>> back;
        for (int i = n-1; i >= 0; i--) {
            back[arr[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        vector<bool> in_queue(n, false);
        unordered_set<int> used;
        q.emplace(0, 0);
        in_queue[0] = true;
        while (!q.empty()) {
            int i = q.front().first;
            int s = q.front().second;
            q.pop();
            if (i == n-1) {
                return s;
            }
            if (!used.count(arr[i])) {
                for (auto& e : back[arr[i]]) {
                    if (!in_queue[e]) {
                        q.emplace(e, s+1);
                        in_queue[e] = true;
                    }
                }
            }
            used.insert(arr[i]);
            if (i) {
                if (!in_queue[i-1]) {
                    q.emplace(i-1, s+1);
                    in_queue[i-1] = true;
                }
            } 
            if (i != n-1) {
                if (!in_queue[i+1]) {
                    q.emplace(i+1, s+1);
                    in_queue[i+1] = true;
                }
            }
        }
        return -1;
    }
};
