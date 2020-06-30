# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        if not root:
            return True
        val = root.val
        stack = []
        
        while len(stack) != 0 or root:
            while root:
                stack.append(root)
                root = root.left
                
            root = stack.pop()
            
            if root.val != val:
                return False
            
            root = root.right
        return True
