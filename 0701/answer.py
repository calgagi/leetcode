# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        if root.val > val:
            if root.left:
                self.insertIntoBST(root.left, val)
            else:
                root.left = TreeNode(val)
        elif root.val < val:
            if root.right:
                self.insertIntoBST(root.right, val)
            else:
                root.right = TreeNode(val)
        return root
