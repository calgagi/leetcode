class Solution {
public:
    vector<string> a;
    
    int dfs(int bm, int j) {
        int res = 0;
        for (int i = j; i < a.size(); i++) {
            bool good = 1;
            int new_bm = bm;
            for (int k = 0; k < a[i].size(); k++) {
                if ((bm & (1 << (a[i][k]-'a'))) || (new_bm & (1 << (a[i][k]-'a')))) {
                    good = 0;
                    break;
                }
                new_bm |= (1 << (a[i][k]-'a'));
            }
            if (!good) {
                continue;
            }
            res = max(res, (int)a[i].size()+dfs(new_bm, i+1));
        }
        return res;
    }
    
    
    int maxLength(vector<string>& arr) {
        this->a = arr;
        return dfs(0, 0);
    }
};
