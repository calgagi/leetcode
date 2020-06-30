"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        rList = []
        self.postorderHelper(root, rList)
        return rList

    def postorderHelper(self, root, rList):
        if root == None:
            return
        for i in root.children:
            self.postorderHelper(i, rList)
        rList.append(root.val)

        
