# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        sum_BST = 0
        if root.left != None:
            sum_BST += self.rangeSumBST(root.left, L, R)
        if root.right != None:
            sum_BST += self.rangeSumBST(root.right, L, R)
        if root.val <= R and root.val >= L:
            sum_BST += root.val
        return sum_BST
