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
        nodes = []
        self.depth_first_search(root, nodes)
        for n in range(len(nodes)-1):
            nodes[n].right = nodes[n+1]
            nodes[n].left = None
        nodes[len(nodes)-1].right = None
        nodes[len(nodes)-1].left = None
        return nodes[0]


    def depth_first_search(self, root, nodes):
        if root == None:
            return
        if root.left != None:
            self.depth_first_search(root.left, nodes)
        nodes.append(root)
        if root.right != None:
            self.depth_first_search(root.right, nodes)
            
