class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end(), greater<int>());
            if (stones[0] != stones[1]) {
                stones.push_back(abs(stones[0]-stones[1]));
            }
            stones.erase(stones.begin());
            stones.erase(stones.begin());
        }
        if (stones.empty()) return 0;
        return stones[0];
    }
};
