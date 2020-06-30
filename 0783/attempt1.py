# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: 'TreeNode') -> 'int':
        if not root:
            return 9223372036854775807
        if root.left and root.right:
            return min(abs(root.left.val - root.val), abs(root.right.val - root.val), self.minDiffInBST(root.left), self.minDiffInBST(root.right))
        elif root.left:
            return min(abs(root.left.val - root.val), self.minDiffInBST(root.left))
        elif root.right:
            return min(abs(root.right.val - root.val), self.minDiffInBST(root.right))
        return 9223372036854775807
