# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int], bound = float('inf')) -> TreeNode:
        if 0 == len(preorder) or preorder[0] > bound:
            return None
        root = TreeNode(preorder.pop(0))
        root.left = self.bstFromPreorder(preorder, root.val)
        root.right = self.bstFromPreorder(preorder, bound)
        return root
        
