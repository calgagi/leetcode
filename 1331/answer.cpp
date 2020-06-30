class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        vector<int> arr = a;
        int n = arr.size();
        if (n == 0) return arr;
        sort(arr.begin(), arr.end());
        unordered_map<int,int> m;
        vector<int> res(n);
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (!m.count(arr[i])) m[arr[i]] = ++counter;
        }
        for (int i = 0; i < n; i++)
            res[i] = m[a[i]];
        return res;
    }
};
