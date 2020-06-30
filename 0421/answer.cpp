class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, max = 0;
        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            
            unordered_set<int> s;
            for (int j = 0; j < nums.size(); j++) {
                s.insert((mask & nums[j]));
            }
            int tmp = max | (1 << i);
            for (int n : s) {
                int search = n ^ tmp;
                if (s.find(search) != s.end()) {
                    max = tmp;
                    break;
                }
            } 
        }
        return max;
    }
};
