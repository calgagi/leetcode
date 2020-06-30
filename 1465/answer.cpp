class Solution {
public:
    int maxArea(int h, int w, vector<int>& hcuts, vector<int>& vcuts) {
        const int M = 1e9+7;
        sort(hcuts.begin(), hcuts.end());
        sort(vcuts.begin(), vcuts.end());
        hcuts.insert(hcuts.begin(), 0);
        vcuts.insert(vcuts.begin(), 0);
        hcuts.push_back(h);
        vcuts.push_back(w);
        int max_h = 1, max_v = 1;
        for (int i = 1; i < hcuts.size(); i++) {
            max_h = max(max_h, hcuts[i] - hcuts[i-1]);
        }
        for (int i = 1; i < vcuts.size(); i++) {
            max_v = max(max_v, vcuts[i] - vcuts[i-1]);
        }
        return ((long long) max_h * (long long) max_v) % M;
    }
};
