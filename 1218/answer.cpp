class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> seen;
        int m = 1;
        for (int i = 0; i < arr.size(); i++) {
            int t = 1;
            if (seen.find(arr[i]-difference) != seen.end())
                t = seen[arr[i]-difference]+1;
            m = max(m, t);
            seen[arr[i]] = t;
        }
        return m;
    }
};
