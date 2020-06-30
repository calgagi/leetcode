class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> seen;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if ((arr[i] % 2 == 0 && seen.count(arr[i] / 2)) || seen.count(arr[i]*2)) {
                return true;
            }
            seen.insert(arr[i]);
        }
        return false;
    }
};
