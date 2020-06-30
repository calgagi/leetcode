# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack = [[root, 0]]
        r = 0
        while len(stack) != 0:
            root = stack.pop()
            left = root[1]
            root = root[0]
            if not root.left and not root.right and left:
                r += root.val
                continue
            if root.left:
                stack.append([root.left, 1])
            if root.right:
                stack.append([root.right, 0])
        
        return r
