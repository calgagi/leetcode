class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> t(timePoints.size());
        for (int x = 0; x < timePoints.size(); x++) {
            string h[2];
            for (int i = 0, j = 0; i < timePoints[x].length(); i++) {
                if (timePoints[x][i] == ':') {
                    j++;
                    continue;
                }
                h[j] += timePoints[x][i];
            }
            t[x] = stoi(h[0])*60 + stoi(h[1]);
        }
        sort(t.begin(), t.end());
        int r = 24*60 - t.back() + t[0];
        for (int i = 1; i < t.size(); i++) {
            r = min(r, t[i] - t[i-1]);  
        }
        return r;
    }
};
