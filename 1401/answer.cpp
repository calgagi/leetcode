class Solution {
public:
    bool checkOverlap(double radius, double x, double y, double x1, double y1, double x2, double y2) {
        if (x <= max(x1,x2) && x >= min(x1,x2) && y <= max(y1,y2) && y >= min(y1,y2)) {
            return 1;
        }
        vector<pair<double,double>> points = {{x1,y1},{x2,y2},{x1,y2},{x2,y1}};
        for (pair<double,double>& p : points) {
            double diffX = p.first-x, diffY = p.second-y;
            if (sqrt(diffX*diffX+diffY*diffY) <= radius) {
                return 1;
            }
            if ((abs(p.first-x)<=radius && y <= max(y1,y2) && y >= min(y1,y2)) ||
                (abs(p.second-y)<=radius && x <= max(x1,x2) && x >= min(x1,x2))) {
                return 1;
            }
        }
        return 0;
    }
};
