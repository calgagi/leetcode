class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int r = 0, m = 0;
        for (int i = 0; i < arr.size(); i++) {
            m = max(m, arr[i]);
            r += (int) (i == m);
        }
        return r;
    }
};
