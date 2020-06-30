class Solution {
public:
    int binary_search(int a, vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int min_dist = INT_MAX, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            min_dist = min(min_dist, abs(h[m]-a));
            if (a < h[m]) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        if (m) {
            min_dist = min(min_dist, abs(h[m-1]-a));
        }
        if (m < (int) h.size()-1) {
            min_dist = min(min_dist, abs(h[m+1]-a));
        }
        return min_dist;
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int n = houses.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, binary_search(houses[i], heaters));
        }
        return res;
    }
};
