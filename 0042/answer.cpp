class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, c = 0, r = height.size()-1;
        int lm = INT_MIN, rm = INT_MIN;
        while (l <= r) {
            if (height[l] <= height[r]) {
                lm = max(height[l], lm);
                c += lm-height[l];
                l++;
            } else {
                rm = max(height[r], rm);
                c += rm-height[r];
                r--;
            }
        }
        return c;
    }
}; 
