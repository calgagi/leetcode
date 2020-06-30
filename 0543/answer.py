# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 0
    
        def depth(r: TreeNode) -> int:
            if not r:
                return 0
            left, right = depth(r.left), depth(r.right)
            self.ans = max(self.ans, left+right)
            return 1 + max(left, right)
        
        depth(root)
        return self.ans
