class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        bitset<3001> b;
        b[0] = 1;
        int t = 0, r = 100;
        for (int s : stones) {
            t += s;
            for (int i = 3000; i >= s; i--) {
                b[i] = b[i] + b[i-s];
            }
        }
        
        for (int i = t / 2; i >= 0; i--)
            if (b[i]) return t - i - i;
        return 0;
    }
};
