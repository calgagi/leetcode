class Solution {
public:
    static bool compare(const vector<int>& lhs, const vector<int>& rhs) {
        if (lhs[1] != rhs[1]) {
            return lhs[1] < rhs[1];
        }
        return lhs[0] < rhs[0];
    }
    
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), compare);
        vector<bool> taken(1e5 + 10, 0);
        int ans = 0;
        for (int i = 0; i < events.size(); i++) {
            for (int j = events[i][0]; j <= events[i][1]; j++) {
                if (!taken[j]) {
                    taken[j] = 1;
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
