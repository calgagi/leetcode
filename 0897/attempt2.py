# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        new_root = root
        while new_root.left != None:
            new_root = new_root.left

        self.reorder_tree(root)
        return new_root

    def reorder_tree(self, root):
        if root.left == None and root.right == None:
            return root
        if root.right != None:
            self.reorder_tree(root.right)
        if root.left != None:
            new_root = self.reorder_tree(root.left)
            root.left = None
            new_root.right = root
            return new_root
