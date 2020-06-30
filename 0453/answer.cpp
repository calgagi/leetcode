class Solution {
public:
    class Compare {
        public:
            bool operator() (vector<int> p1, vector<int> p2) {
                if (p1[1] == p2[1]) 
                    return (p1[1] - p1[0]) > (p2[1] - p2[0]);
                return p1[1] < p2[1];
            }
    };
    
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), Compare());
        int r = 0;
        long long p = -INFINITY;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] > p) {
                p = points[i][1];
                r += 1;
            }
        }
        return r;
    }
};
