# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        # DFS
        if not root:
            return
        stack = [root]
        dfs = []
        while len(stack):
            it = stack.pop()
            dfs.append(it)
            if it.right:
                stack.append(it.right)
            if it.left:
                stack.append(it.left)
                
        for i in range(len(dfs)-1):
            dfs[i].right = dfs[i+1]
            dfs[i].left = None
        dfs[-1].right = None
