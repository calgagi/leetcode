class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> p(n+1, 0);
        for (int i = 0; i < bookings.size(); i++) {
            p[bookings[i][0]-1] += bookings[i][2];
            p[bookings[i][1]] -= bookings[i][2];
        }
        int t = 0;
        for (int i = 0; i < p.size()-1; i++) {
            t += p[i];
            p[i] = t;
        }
        p.erase(p.end()-1);
        return p;
    }
};
