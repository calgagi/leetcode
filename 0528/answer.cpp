class Solution {
public:
    vector<int> p;
    int t;
    
    Solution(vector<int>& w) {
        srand(time(NULL));
        p.assign(w.size()+1, 0);
        for (int i = 1; i < p.size(); i++) {
            p[i] = p[i-1] + w[i-1];
        }
        t = p[p.size()-1];
        return;
    }
    
    int pickIndex() {
        int x = rand() % t;
        int l = 0, r = p.size()-2, ans;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (p[m] <= x) {
                ans = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
