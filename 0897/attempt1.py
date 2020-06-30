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
        new_root, new_root_root = root, None
        if root == None:
            return None
        elif root.left == None and root.right == None:
            return root
        if root.left != None:
            new_root = self.reorder_tree(root.left)
            new_root.right = root
            root.left = None
        if root.right != None:
            new_root_root = self.reorder_tree(root.right)
            new_root_root.right = new_root
            return new_root_root
        else: return new_root
