# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        from collections import defaultdict
        seen = defaultdict(int)
        self.robHelp(root, seen)
        return seen[root]
        
    def robHelp(self, root: TreeNode, seen) -> int:
        if not root:
            return 0
        if seen[root] != 0:
            return seen[root]
        
        r = root.val
        if root.right:
            r += self.robHelp(root.right.left, seen) + self.robHelp(root.right.right, seen)
        if root.left:
            r += self.robHelp(root.left.left, seen) + self.robHelp(root.left.right, seen)
        
        seen[root] = max(r, self.robHelp(root.left, seen) + self.robHelp(root.right, seen))
        return seen[root]
