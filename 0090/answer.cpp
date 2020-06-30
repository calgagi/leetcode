class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        stack<pair<vector<int>, int>> s;
        s.push({vector<int>(), 0});
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        while (!s.empty()) {
            int i = s.top().second;
            vector<int> t = s.top().first;
            s.pop();
            res.push_back(t);
            unordered_set<int> seen;
            for ( ; i < nums.size(); i++) {
                if (seen.find(nums[i]) != seen.end())
                    continue;
                seen.insert(nums[i]);
                t.push_back(nums[i]);
                s.push({t, i+1});
                t.pop_back();
            }
        }
        return res;
    } 
};
