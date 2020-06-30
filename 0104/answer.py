# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        totalDepthL, totalDepthR = 0, 0
        if root.left != None:
            totalDepthL = self.explore(root.left, totalDepthL)
        if root.right != None:
            totalDepthR = self.explore(root.right, totalDepthR)
        return max(totalDepthL, totalDepthR) + 1

    def explore(self, root, totalDepth):
        totalDepthL, totalDepthR = 0, 0
        if root.left != None:
            totalDepthL = self.explore(root.left, totalDepth)
        if root.right != None:
            totalDepthR = self.explore(root.right, totalDepth)
        return max(totalDepthL, totalDepthR) + 1
