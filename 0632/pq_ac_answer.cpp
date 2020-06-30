class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // O(k * max_len(nums))
        const int k = nums.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> idx(k, 0), res, candidate = {INT_MAX, 0};

        for (int i = 0; i < k; i++) {
            q.push({nums[i][0], i});
            candidate[1] = max(candidate[1], nums[i][0]);
        }
        candidate[0] = q.top().first;
        res = candidate;
        
        while (true) {
            int popper = q.top().second;
            q.pop();
            idx[popper]++;
            if (idx[popper] >= nums[popper].size()) break;
            q.push({nums[popper][idx[popper]], popper});
            candidate[0] = q.top().first;
            candidate[1] = max(candidate[1], nums[popper][idx[popper]]);
            if (candidate[1]-candidate[0] < res[1]-res[0]) {
                res = candidate;
            }
        }
        return res;
    }
};
