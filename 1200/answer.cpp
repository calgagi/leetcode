class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> r; int m = INT_MAX;
        for (int i = 0; i < arr.size()-1; i++) {
            m = min(m, abs(arr[i+1] - arr[i]));
        }
        for (int i = 0; i < arr.size()-1; i++) {
            if (abs(arr[i+1] - arr[i]) == m)
                r.push_back({arr[i], arr[i+1]});
        }
        return r;
    }
};
