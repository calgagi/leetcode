bool compare(vector<int>& l, vector<int>& r) {
    return l[1] < r[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int r = 1, start = pairs[0][1];
        for (int i = 1; i < pairs.size(); i++) {
            if (start < pairs[i][0]) {
                r++;
                start = pairs[i][1];
            }
        }
        return r;
    }
};
