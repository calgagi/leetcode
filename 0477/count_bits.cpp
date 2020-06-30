class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < sizeof(int)*8; i++) {
            int y = 0;
            for (int& j : nums) {
                y += 1 & (j >> i);
            }
            x += y * (nums.size() - y);
        }
        return x;
    }
};
