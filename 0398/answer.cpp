class Solution {
public:
    unordered_map<int, vector<int>> indices;
    Solution(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            indices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int random = rand() % indices[target].size();
        return indices[target][random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
