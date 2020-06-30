class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> r;
        unordered_map<int, int> x;
        for (int i = 0; i < nums.size(); i++) x[nums[i]]++;
        for (auto it = x.begin(); it != x.end(); it++)
            if (it->second == 1) r.push_back(it->first); 
        return r;
    }
};
