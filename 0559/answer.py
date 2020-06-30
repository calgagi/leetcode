"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        max_depth = 0
        if root == None:
            return 0
        for i in root.children:
            max_depth = max(self.maxDepth(i), max_depth)
        return max_depth + 1

        
