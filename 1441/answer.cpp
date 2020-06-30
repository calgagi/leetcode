class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        bool s = 0;
        for (int j = 0, i = 1; j < target.size() && i <= n; i++) {
            if (target[j] == i) {
                ans.push_back("Push");
                j++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};
