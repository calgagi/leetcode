"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        rList = []

        self.get_preorder(root, rList)

        return rList

    def get_preorder(self, root, rList):
        if root == None:
            return
        rList.append(root.val)
        for i in range(len(root.children)):
            self.get_preorder(root.children[i], rList)
        
