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
    int r = 0;
    int distributeCoins(TreeNode* root) {
        helper(root);
        return r;
    }
    
    int helper(TreeNode* root){
        int coinsR = 0, coinsL = 0, coins = root->val;
        if (root->right) {
            coinsR = helper(root->right);
        }
        if (root->left) {
            coinsL = helper(root->left);
        }
        r += abs(coinsR) + abs(coinsL); 
        return coinsR + coinsL + (coins - 1);  
    }
};
