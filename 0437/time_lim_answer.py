# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        from collections import defaultdict
        self.r = 0
        self.s = None
        self.seen = defaultdict(int)
        
    def pathSum(self, root: TreeNode, sum: int) -> int:
        self.s = sum
        
        self.pathSumHelper(root, self.s, [])
        return self.r
    
    def pathSumHelper(self, root: TreeNode, sum: int, path: List[int]) -> None:
        path.append(root)
        if self.seen[str(path)] == 0:
            if root and sum-root.val == 0:
                self.r += 1
            if root:
                self.seen[str(path)] = 1
                self.pathSumHelper(root.left, sum-root.val, path)
                self.pathSumHelper(root.right, sum-root.val, path)
                self.pathSumHelper(root.left, self.s, [])
                self.pathSumHelper(root.right, self.s, [])

