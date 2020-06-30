class Solution {
public:
    int gcd(int a, int b) { 
        if (a == 0) 
            return b; 
        return gcd(b % a, a); 
    }
    
    bool isGoodArray(vector<int>& nums) {
        int m = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            m = gcd(m, nums[i]);
            if (m == 1) return true;
        }
        return false;
    }
};
