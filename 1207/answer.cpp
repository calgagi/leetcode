class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> occ;
        for (int &i : arr) occ[i]++;
        unordered_map<int,int> n;
        for (auto it = occ.begin(); it != occ.end(); it++) {
            n[it->second]++;
            if (n[it->second] >= 2) return false;
        }
        return true;
    }
};
