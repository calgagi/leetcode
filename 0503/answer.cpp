class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> r(nums.size(), -1);
        stack<pair<int, int>> s;
        for (int i = 0, j = 0; j < nums.size()*2; j++, i = (i+1) % nums.size()) {
            while (!s.empty() && s.top().first < nums[i]) {
                r[s.top().second] = nums[i];
                s.pop();
            }
            if (j < nums.size()) {
                s.push({nums[i], i});
            }
        }
        return r;
    }
};
