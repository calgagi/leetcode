class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in(N, 0), out(N, 0);
        for (vector<int>& x : trust) {
            out[x[0]-1]++;
            in[x[1]-1]++;
        }
        int ans = -1;
        for (int i = 0; i < N; i++) {
            if (in[i] == N-1 && out[i] == 0) {
                if (ans != -1) {
                    return -1;
                }
                ans = i+1;
            }
        }
        return ans;
    }
};
