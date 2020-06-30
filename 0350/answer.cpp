class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> s;
        for (auto& i : nums1) s[i]++;
        vector<int> res;
        for (auto& i : nums2)
            if (s[i] >= 1) {
                s[i]--;
                res.push_back(i);
            }
        return res;
    }
};
