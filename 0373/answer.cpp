class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        for (int i = 0; i < (int) nums1.size(); i++) {
            for (int j = 0; j < (int) nums2.size(); j++) {
                ans.push_back({nums1[i], nums2[j]});
            }
        }
        sort(ans.begin(), ans.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0]+a[1] < b[0]+b[1];
        });
        while (ans.size() > k) {
            ans.pop_back();
        }
        return ans;
    }
};
