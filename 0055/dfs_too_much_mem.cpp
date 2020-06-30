class Solution {
public:
    bool canJump(vector<int>& nums) {
        stack<int> s;
        s.push(0);
        unordered_map<int,bool> seen;
        while (!s.empty()) {
            int t = s.top(); s.pop();
            if (seen.find(t) != seen.end()) continue;
            if (t >= nums.size()) continue;
            if (t == nums.size()-1) return true;
            seen[t] = true;
            for (int m = t + nums[t]; m > t; m--) s.push(m);
        }
        return false;
    }
};
