class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int j;
        vector<int> r(days.size()+1, INFINITY);
        r[0] = 0;
        for (int i = 1; i < r.size(); i++) {
            int s = i, t = i;
            while (s > 0 && days[i-1] - days[s-1] < 7) s--;
            while (t > 0 && days[i-1] - days[t-1] < 30) t--;
            r[i] = min(r[i], min(r[i-1]+costs[0], min(r[s]+costs[1], r[t]+costs[2]))); 
        }
        return r.back();
    }
};
