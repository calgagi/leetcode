class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> c;
        for (auto& x : nums) c[x]++;
        for (auto it : c)
            if (it.second > nums.size() / 3)
                res.push_back(it.first);
        return res;
    }
};
