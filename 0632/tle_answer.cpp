class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // O(k * max_len(nums))
        const int k = nums.size();
        vector<int> idx(k, 0), res;
        int range = INT_MAX;
        while (true) {
            vector<int> candidate = {INT_MAX, 0};
            int popper = -1;
            for (int i = 0; i < k; i++) {
                if (candidate[0] > nums[i][idx[i]]) {
                    candidate[0] = nums[i][idx[i]];
                    popper = i;
                }
                candidate[1] = max(candidate[1], nums[i][idx[i]]);
            }
            if (candidate[1]-candidate[0] < range) {
                range = candidate[1]-candidate[0];
                res = candidate;
            }
            if (idx[popper] < nums[popper].size()-1) idx[popper]++;
            else break;
        }
        return res;
    }
};
