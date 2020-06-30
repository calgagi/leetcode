class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> seen;
        for (string& t : words) seen[t]++;
        priority_queue<pair<int,string>> pq;
        for (auto it = seen.begin(); it != seen.end(); it++)
            pq.push({it->second, it->first});
        vector<string> res;
        int i = 0;
        while (i < k) {
            int prev = pq.top().first;
            vector<string> level;
            while (!pq.empty() && prev == pq.top().first) {
                level.push_back(pq.top().second);
                pq.pop();
            }
            sort(level.begin(), level.end());
            for (int j = 0; j < level.size() && i < k; i++, j++) res.push_back(level[j]);
        }
        return res;
    }
};
