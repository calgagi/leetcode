class Solution {
public:    
    int numRollsToTarget(int d, int f, int target) {
        int m = (10e8) + 7;
        int* dp_old = new int[target+1];
        for (int i = 0; i <= target; i++) {
            if (i <= f && i) dp_old[i] = 1;
            else dp_old[i] = 0;
        }
        for (int i = 1; i < d; i++) {
            int *dp_new = new int[target+1];
            for (int j = 0; j <= target; j++) {
                if (j <= i) {
                    dp_new[j] = 0;
                    continue;
                }
                long long x = 0;
                for (int k = j-1; k >= max(1, j-f); k--) {
                    x = (x + dp_old[k]) % m;
                }
                dp_new[j] = x;
            }       
            dp_old = dp_new;
        }
        return dp_old[target];
    }
};
