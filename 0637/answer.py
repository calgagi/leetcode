# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: TreeNode
        :rtype: List[float]
        """
        nodes = []
        self.getNodes(root, 0, nodes)
        avgs = []
        for level in nodes:
            avgs.append(float(sum(level))/float(len(level)))
        return avgs


    def getNodes(self, root, level, nodes):
        if root != None:
            if len(nodes)-1 < level:
                nodes.append([])
            nodes[level].append(root.val)
            if root.right != None:
                self.getNodes(root.right, level+1, nodes)
            if root.left != None:
                self.getNodes(root.left, level+1, nodes)
        
