class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for(auto& p1 : points) {
            unordered_map<double, int> seen;
            for(auto& p2 : points) {
                if (&p1 == &p2) continue;
                double d = sqrt(pow(p1[0]-p2[0],2) + pow(p1[1]-p2[1], 2));
                if (seen.count(d))
                    res += seen[d]*2;
                seen[d]++;
            }
        }
        return res;
                
    }
};
