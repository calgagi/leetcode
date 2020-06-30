class Solution {
public:
    int k, n;
    long double fact[49];
    long double count = 0, total = 0;
    vector<int> balls;
    
    void dfs(int i, int count1, int count2, long double permutation1, long double permutation2, int color1, int color2) {
        if (count1 == 0 && count2 == 0) {
            if (color1 == color2) {
                count += (permutation1 * permutation2);
            }
            total += (permutation1 * permutation2);
        } else if (count1 >= 0 && count2 >= 0) {
            for (int ball1 = 0; ball1 <= balls[i]; ball1++) {
                int ball2 = balls[i]-ball1;
                dfs(i+1, count1-ball1, count2-ball2, permutation1/fact[ball1], permutation2/fact[ball2], color1 + (ball1 > 0), color2 + (ball2 > 0));
            }
        }
        return;
    }
    
    double getProbability(vector<int>& balls) {
        this->balls = balls;
        n = accumulate(balls.begin(), balls.end(), 0);
        k = balls.size();
        fact[0] = 1;
        for (int i = 1; i < 49; i++) {
            fact[i] = fact[i-1] * i;
        }
        dfs(0, n/2, n/2, fact[n/2], fact[n/2], 0, 0);
        return count/total;
    }
};
