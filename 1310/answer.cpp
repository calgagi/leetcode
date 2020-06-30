class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int n = arr.size();
        vector<int> res, pre(n+1, 0);
        for (int i = 1; i < n+1; i++)
            pre[i] = pre[i-1] ^ arr[i-1];
        for (auto& query : queries) {
            int l = query[0]+1, r = query[1]+1;
            res.push_back(pre[l-1] ^ pre[r]);
        }
        return res;
    }
};
