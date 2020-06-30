class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](const int& a, const int& b) {
            int ba = __builtin_popcount(a), bb = __builtin_popcount(b);
            return ba==bb ? a < b : ba < bb;
        });
        return arr;
    }
};
