class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = 0, m = reservedSeats.size();
        int v = n;
        sort(reservedSeats.begin(), reservedSeats.end());
        int i = 0;
        while (i < m) {
            int r = reservedSeats[i][0];
            vector<bool> f(11, 1);
            while (i < m && reservedSeats[i][0] == r) {
                f[reservedSeats[i][1]] = 0;
                i++;
            }
            int streak = 0;
            if (f[2] && f[3] && f[4] && f[5] && f[6] && f[7] && f[8] && f[9]) {
                res += 2;
            } else if ((f[2] && f[3] && f[4] && f[5]) || (f[6] && f[7] && f[8] && f[9]) || (f[4] && f[5] && f[6] && f[7])) {
                res++;
            }
            v--;
        }
        return v*2 + res;
    }
};
