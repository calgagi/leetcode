class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Greedy: Take maximum area covered
        int area[n];
        int covered_area = 0;
        memset(area, 0, sizeof(area));
        vector<pair<int,int>> r;
        for (int i = 0; i <= n; i++) {
            if (ranges[i] == 0) continue;
            r.push_back({max(0, i-ranges[i]), min(n-1, i+ranges[i]-1)});
        }
        int res = 0;
        while (covered_area < n && !r.empty()) {
            int max_area_ele = -1, max_area = 0;
            for (int i = 0; i < (int) r.size(); i++) {
                // Find max area that one covers
                int cur = 0;
                for (int j = r[i].first; j <= r[i].second; j++) {
                    if (area[j] == 0) {
                        cur++;
                    }
                }
                if (cur == 0) {
                    r.erase(r.begin()+i);
                    i--;
                    continue;
                }
                if (cur > max_area) {
                    max_area = cur;
                    max_area_ele = i;
                }
            }
            // Cover that area
            for (int i = r[max_area_ele].first; i <= r[max_area_ele].second; i++) {
                if (!area[i]) {
                    covered_area++;
                    area[i] = 1;
                }
            }
            res++;
        }
        return (covered_area == n ? res : -1);
    }
};
