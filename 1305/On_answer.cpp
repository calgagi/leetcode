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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> q1, q2;
        while (root1) {
            q1.push(root1);
            root1 = root1->left;
        }
        while (root2) {
            q2.push(root2);
            root2 = root2->left;
        }
        while (!q1.empty() || !q2.empty()) {
            TreeNode* i1 = NULL, * i2 = NULL;
            if (!q1.empty()) {
                i1 = q1.top();
            }
            if (!q2.empty()) {
                i2 = q2.top();
            }
            if (i1 != NULL && i2 != NULL) {
                if (i1->val < i2->val) {
                    res.push_back(i1->val);
                    q1.pop();
                    i1 = i1->right;
                    while (i1) {
                        q1.push(i1);
                        i1 = i1->left;
                    }
                } else {
                    res.push_back(i2->val);
                    q2.pop();
                    i2 = i2->right;
                    while (i2) {
                        q2.push(i2);
                        i2 = i2->left;
                    }
                }
            } else if (i1 != NULL) {
                res.push_back(i1->val);
                q1.pop();
                i1 = i1->right;
                while (i1) {
                    q1.push(i1);
                    i1 = i1->left;
                }
            } else if (i2 != NULL) {
                res.push_back(i2->val);
                q2.pop();
                i2 = i2->right;
                while (i2) {
                    q2.push(i2);
                    i2 = i2->left;
                }
            }
        }
        return res;
    }
};
