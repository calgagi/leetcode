/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (nums.size() == 0) {
            return NULL;
        }
        int m = l + (r - l) / 2;
        if (l>r) {
            return NULL;
        }
        TreeNode* res = new TreeNode(nums[m]);
        res->left = helper(nums, l, m-1);
        res->right = helper(nums, m+1, r);
        return res;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};
