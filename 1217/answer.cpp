class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int o = 0, e = 0;
        for (int i = 0; i < chips.size(); i++) {
            if (chips[i] % 2 == 0) e++;
            else o++;
        }
        return min(o,e);
    }
};
