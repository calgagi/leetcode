class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Counting sort
        vector<int> counts(3, 0);
        for (auto& n : nums) counts[n]++;
        for (auto& n : nums) {
            for (int i = 0; i < 3; i++) {
                if (counts[i]) {
                    counts[i]--;
                    n = i;
                    break;
                }
            }
        }
    }
};
