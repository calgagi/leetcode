# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        queue = [[root, 0, None]]
        xf, yf = None, None
        while len(queue) != 0:
            node = queue.pop(0)
            if not xf and node[0].val == x:
                xf = node
            elif not yf and node[0].val == y:
                yf = node
            if xf and yf:
                break
            if node[0].right:
                queue.append([node[0].right, node[1] + 1, node[0]])
            if node[0].left:
                queue.append([node[0].left, node[1] + 1, node[0]])
        if not xf or not yf:
            return False
        if xf[1] == yf[1] and xf[2] != yf[2]:
            return True
        return False
