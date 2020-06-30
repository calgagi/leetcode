class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto compare = [](const pair<int,int>& a, const pair<int,int>& b) {
            return sqrt(a.first*a.first + a.second*a.second) > sqrt(b.first*b.first + b.second*b.second);
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(compare)> q(compare);
        vector<vector<int>> ans;
        for (vector<int>& p : points) {
            q.push({p[0], p[1]});
        }
        while (K--) {
            ans.push_back({q.top().first, q.top().second});
            q.pop();
        }
        return ans;
    }
};
