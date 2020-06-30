# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: 'TreeNode') -> 'int':
        seen = []
        self.inorder(root, seen)
        x = 10000000000000000000
        for i in range(len(seen)-1):
            x = min(x, abs(seen[i]-seen[i+1]))
        return x

    def inorder(self, root, seen):
        if root.left:
            self.inorder(root.left, seen)
        seen.append(root.val)
        if root.right:
            self.inorder(root.right, seen)
        
