class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0) return 0;
        sort(timeSeries.begin(), timeSeries.end());
        int r = 0;
        for (int i = 0; i < timeSeries.size()-1; i++) {
            r += min(timeSeries[i+1]-timeSeries[i], duration);
        }
        return r + duration;
    }
};
