class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0, n = rating.size();
        for (int i = 0; i < n; i++) {
            int bb = 0, ba = 0, ab = 0, aa = 0;
            for (int j = 0; j < i; j++) {
                if (rating[j] < rating[i]) {
                    bb++;
                } else if (rating[j] > rating[i]) {
                    ba++;
                }
            }
            for (int j = i+1; j < n; j++) {
                if (rating[j] < rating[i]) {
                    ab++;
                } else if (rating[j] > rating[i]) {
                    aa++;
                }
            }
            ans += (bb*aa) + (ba*ab); 
        }
        return ans;
    }
};
