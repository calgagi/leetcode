# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.helper(root, 0)
        return root

    def helper(self, root, val):
        if not root:
            return val
        root.val += self.helper(root.right, val)
        return self.helper(root.left, root.val)
        
