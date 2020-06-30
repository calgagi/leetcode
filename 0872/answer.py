# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        return self.leaves(root1) == self.leaves(root2)

    def leaves(self, root):
        if root.left == None and root.right == None:
            return [root.val]

        rList = []
        if root.left != None:
            rList += self.leaves(root.left)
        if root.right != None:
            rList += self.leaves(root.right)
        return rList
        
