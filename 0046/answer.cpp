class Solution {
public:
    vector<vector<int>> r;
    
    void permute(vector<int>& c, vector<int>& nums) {
        if (nums.empty()) {
            r.push_back(c);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            c.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            permute(c, nums);
            nums.insert(nums.begin()+i, c.back());
            c.pop_back();
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> c;
        permute(c, nums);
        return this->r; 
    }
};
