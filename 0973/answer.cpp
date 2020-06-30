class Solution {
public:
    class Compare {
        public:
        bool operator() (vector<int> const& a, vector<int> const& b) {
            return a[2] > b[2];
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for (int i = 0; i < points.size(); i++) {
            points[i].push_back(pow(points[i][0], 2) + pow(points[i][1], 2));
            pq.push(points[i]);
        }
        vector<vector<int>> r;
        for (int i = 0; i < K; i++) {
            vector<int> b = pq.top(); pq.pop();
            b.pop_back();
            r.push_back(b);
        }
        return r;
    }
};
