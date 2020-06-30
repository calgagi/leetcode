# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        stack = [root]
        r = []
        
        while len(stack) != 0:
            # Dive
            root = stack.pop()
            if root:    
                stack.append(root.right)
                stack.append(root.left)
                r.append(root.val)
                
        return r
        
