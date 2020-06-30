class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int r = 0;
        vector<int> x = heights;
        sort(x.begin(), x.end());
        for (int i = 0; i < heights.size(); i++) {
            if (x[i] != heights[i]) r++;
        }
        return r;
    }
};
