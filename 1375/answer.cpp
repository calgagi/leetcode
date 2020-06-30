class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int mx = 0, res = 0, n = light.size(), cur = 0;
        //cout << "start" << endl;
        vector<bool> on(n, 0);
        for (int i = 0; i < n; i++) {
            light[i]--;
            on[light[i]] = 1;
            while (cur < n && on[cur]) {
                cur++;
            }
            mx = max(mx, light[i]);
            if (mx == cur-1) {
                res++;
            }
            //cout << cur << " " << mx << endl;
        }
        return res;
    }
};
