class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (auto& i : nums) {
            int e = 0;
            while (i) {
                i /= 10;
                e++;
            }
            if (!(e & 1)) {
                ans++;
            }
        }
        return ans;
    }
};
