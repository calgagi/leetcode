class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> counts;
        for (int i = 0; i < arr1.size(); i++) counts[arr1[i]]++;
        vector<int> r(arr1.size());
        int idx = 0;
        for (int i = 0; i < arr2.size(); i++) {
            while (counts[arr2[i]]) {
                r[idx] = arr2[i];
                counts[arr2[i]]--;
                idx++;
            }
            counts.erase(arr2[i]);
        }
        for (auto it = counts.begin(); it != counts.end(); it++) {
            while (it->second) {
                r[idx] = it->first;
                idx++;
                it->second--;
            }
        }
        return r;
    }
};
