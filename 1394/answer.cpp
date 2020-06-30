class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> s;
        for (auto& i : arr) {
            s[i]++;
        }
        int res = -1;
        for (auto& p : s) {
            if (p.first == p.second) {
                res = max(p.first, res);
            }
        }
        return res;
    }
};
