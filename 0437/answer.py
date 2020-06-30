# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:        
    def pathSum(self, root: TreeNode, sum: int) -> int:
        self.r = 0
        paths = {0:1}
        self.pathSumHelper(root, 0, sum, paths)
        return self.r
    
    def pathSumHelper(self, root: TreeNode, sum_so_far: int, target: int, paths) -> None:
        if root:
            complement = sum_so_far - target + root.val
            if complement in paths:
                self.r += paths[complement]
            paths.setdefault(sum_so_far+root.val, 0)
            paths[sum_so_far+root.val] += 1
            self.pathSumHelper(root.left, sum_so_far+root.val, target, paths)
            self.pathSumHelper(root.right, sum_so_far+root.val, target, paths)
            paths[sum_so_far+root.val] -= 1
        return

