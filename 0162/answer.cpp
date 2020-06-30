class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Binary search
        int l = 0, r = nums.size()-1, m;
        
        while (l <= r) {
            m = (l+r)/2;
            
            bool peakR = false, peakL = false;
            if (m-1 < 0 || nums[m-1] < nums[m]) peakL = true;
            if (m+1 > nums.size()-1 || nums[m+1] < nums[m]) peakR = true;
            if (peakR && peakL) return m;
            
            if (!peakL && m-1 >= 0) r = m-1;
            else if (!peakR && m+1 < nums.size()) l = m+1;
        }
        return -1;
    }
};
