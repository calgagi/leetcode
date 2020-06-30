# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0:
            return None
        m, n = nums[0], 0
        for i, v in enumerate(nums):
            if v > m:
                m, n = v, i
        root = TreeNode(m)
        root.left = self.constructMaximumBinaryTree(nums[0:n])
        root.right = self.constructMaximumBinaryTree(nums[n+1:len(nums)])
        return root
                
