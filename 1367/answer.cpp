/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    bool isSubPath(ListNode* head, TreeNode* root, bool onPath = 0) {
        if (root == NULL || head == NULL) {
            return head == NULL;
        }
        if (head->val == root->val) {
            if (isSubPath(head->next, root->right, 1) || isSubPath(head->next, root->left, 1)) {
                return 1;
            }
            if (onPath) {
                return 0;
            }
        } else if (onPath) {
            return 0;
        }
        return isSubPath(head, root->right, 0) || isSubPath(head, root->left, 0);
    }
};
