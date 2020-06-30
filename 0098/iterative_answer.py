# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        if not root:
            return True
        
        stack, prev = [], None
        
        while root or len(stack) != 0:
            # Go all the way to the left
            while root:
                stack.append(root)
                root = root.left
            
            # Get leftmost node
            root = stack.pop()            
            
            # If there was a previous node (will always be the previous one in inorder trav)
            if prev and root.val <= prev.val:
                return False
            
            # Prev is now this node, go right one
            # If right is none, we get the parent from line 22
            prev = root
            root = root.right
        
        return True
            
