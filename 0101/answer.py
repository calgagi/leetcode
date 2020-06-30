# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        l = []
        r = []
        ri, li = root, root
        
        while len(l) == len(r) != 0 or (li and ri):
            while ri and li:
                r.append(ri)
                l.append(li)
                ri = ri.right
                li = li.left
            if (ri and not li) or (li and not ri):
                return False
            li = l.pop()
            ri = r.pop()
            if li.val != ri.val:
                return False
            ri = ri.left
            li = li.right
        return True
                
                
        
