# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        if not root:
            return 0
        r = root.val
        if root.right and root.left:
            r = max(self.rob(root.left)+self.rob(root.right), self.robSkip(root.left)+self.robSkip(root.right)+r)
        elif root.right:
            r = max(self.rob(root.right), self.robSkip(root.right)+r)
        elif root.left:
            r = max(self.rob(root.left), self.robSkip(root.left)+r)
        return r
            
            
    def robSkip(self, root: TreeNode) -> int:
        if not root:
            return 0
        return self.rob(root.right) + self.rob(root.left)
