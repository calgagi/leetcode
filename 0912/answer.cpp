class Solution {
public:
    void merge_sort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int m = (r - l) / 2;
            merge_sort(nums, l, l+m);
            merge_sort(nums, l+m+1, r);
            merge(nums, l, l+m, r);
        }
    }
    
    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> left;
        vector<int> right;
        for (int i = l; i <= m; i++) left.push_back(nums[i]);
        for (int i = m+1; i <= r; i++) right.push_back(nums[i]);
        
        int li = 0, ri = 0, ii = l;
        while (li < left.size() && ri < right.size()) {
            if (left[li] < right[ri]) {
                nums[ii] = left[li];
                li += 1;
            } else {
                nums[ii] = right[ri];
                ri += 1;
            }
            ii += 1;
        }
        
        while (li < left.size()) {
            nums[ii] = left[li];
            ii += 1; li += 1;
        }
        while (ri < right.size()) {
            nums[ii] = right[ri];
            ii += 1; ri += 1;
        }
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
};
