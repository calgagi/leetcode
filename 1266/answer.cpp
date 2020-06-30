class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 1; i < (int) points.size(); i++) {
            int diffx = abs(points[i-1][0]-points[i][0]);
            int diffy = abs(points[i-1][1]-points[i][1]);
            int diag = min(diffx, diffy);
            res += diag;
            res += abs(diag - diffy);
            res += abs(diag - diffx);
        }
        return res;
    }
};
