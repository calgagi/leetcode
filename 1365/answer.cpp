class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> p;
        for (int i = 0; i < n; i++) {
            p.emplace_back(nums[i], i);
        }
        sort(p.begin(), p.end());
        vector<int> res(n, 0);
        for (int i = 1; i < n; i++) {
            if (p[i].first == p[i-1].first) {
                res[p[i].second] = res[p[i-1].second];
            } else {
                res[p[i].second] = i;
            }
        }
        return res;
    }
};
