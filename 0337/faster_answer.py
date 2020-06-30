# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        seen = {}
        return self.robHelp(root, seen)
            
    def robHelp(self, root: TreeNode, seen) -> int:
        if not root:
            return 0
        elif root in seen:
            return seen[root]
         
        r = 0
        if root.left:
            r += self.robHelp(root.left.left, seen) + self.robHelp(root.left.right, seen)
        if root.right:
            r += self.robHelp(root.right.left, seen) + self.robHelp(root.right.right, seen)
        seen[root] = max(r+root.val, self.robHelp(root.right, seen)+self.robHelp(root.left, seen))
        return seen[root]
        
