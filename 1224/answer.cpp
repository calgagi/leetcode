class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int res = 1;
        unordered_map<int,int> s;
        unordered_map<int,int> c;
        int m = 0;
        int uniquevals = 0;
        for (int i = 0; i < nums.size(); i++) {
            s[nums[i]]++;
            if (s[nums[i]] == 1) uniquevals++;
            c[s[nums[i]]-1]--;
            c[s[nums[i]]]++;
            m = max(s[nums[i]], m);
            if (c[m-1] == uniquevals-1 && c[m] == 1) res = i;
            else if (c[m] == uniquevals-1 && c[1] == 1) res = i;
            else if (m == 1) res = i;
        }
        return res+1;
    }
};
