class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        queue<pair<vector<int>, int>> q;
        q.push({vector<int>(), 0});
        while (!q.empty()) {
            vector<int> t = q.front().first;
            int i = q.front().second;
            q.pop();
            res.push_back(t);
            while (i < nums.size()) {
                t.push_back(nums[i]);
                q.push({t, i+1});
                t.pop_back();
                i++;
            }
        }
        return res;
    }
};
