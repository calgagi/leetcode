class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> m;
        unordered_set<string> seen;
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                for (int k = j+1; k < nums.size(); k++) {
                    int s = target - (nums[i]+nums[j]+nums[k]);
                    if (!m.count(s)) {
                        continue;
                    }
                    for (auto& l : m[s]) {
                        if (l == i || l == j || l == k) {
                            continue;
                        }
                        vector<int> t = {nums[l], nums[i], nums[j], nums[k]};
                        sort(t.begin(), t.end());
                        string s = to_string(t[0]) + " " + to_string(t[1]) + " " + to_string(t[2]) + " " + to_string(t[3]);
                        if (seen.count(s)) {
                            continue;
                        }
                        seen.insert(s);
                        res.push_back({nums[l], nums[i], nums[j], nums[k]});
                    }
                }
            }
            m[nums[i]].push_back(i);
        }
        return res;
    }
};
