class Solution {
public:
    vector<pair<double,double>> pos;
    double best = 1e9, error = 1e-6;
    
    double dist(double x, double y) {
        double ans = 0;
        for (pair<double,double>& p : pos) {
            double diffx = p.first - x;
            double diffy = p.second - y;
            ans += sqrt(diffx*diffx + diffy*diffy);
        }
        return ans;
    }
    
    double ternary(double x) {
        double yl = 0, yr = 100;
        double tbest = 1e9;
        while (yr - yl > error) {
            double m1 = yl + (yr - yl) / 3, m2 = yr - (yr - yl) / 3;
            double val1 = dist(x, m1), val2 = dist(x, m2);
            if (val1 > val2) {
                yl = m1;
            } else {
                yr = m2;
            }
            tbest = min({val1, val2, tbest});
        }
        return tbest;
    }
    
    double getMinDistSum(vector<vector<int>>& positions) {
        for (vector<int>& p : positions) {
            pos.push_back({p[0], p[1]});
        }
        
        double xl = 0, xr = 100;
        while (xr - xl > error) {
            double m1 = xl + (xr - xl) / 3, m2 = xr - (xr - xl) / 3;
            double val1 = ternary(m1), val2 = ternary(m2);
            if (val1 > val2) {
                xl = m1;
            } else {
                xr = m2;
            }
            best = min({val1, val2, best});
        }
        return best;
    }
};
