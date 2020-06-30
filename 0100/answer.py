# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        return self.inorder(p) == self.inorder(q)

    def inorder(self, root):
        r = []
        if not root:
            return r
        if root.left:
            r.append(self.inorder(root.left))
        r.append(root.val)
        if root.right:
            r.append(self.inorder(root.right))
        return r
