# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        stack = []
        while len(stack) != 0 or s:
            while s:
                stack.append(s)
                s = s.left

            s = stack.pop(0)
            
            if s and t.val == s.val:
                if self.isSubTreeHelper(s, t):
                    return True
            if s:
                s = s.right
        return False
                
    def isSubTreeHelper(self, s: TreeNode, t: TreeNode) -> bool:
        stackS = []
        stackT = []
        
        while (len(stackS) != 0 and len(stackT) != 0) or s:
            while s and t:
                stackS.append(s)
                stackT.append(t)
                s = s.left
                t = t.left
            
            if (s and not t) or (t and not s):
                return False
            
            s = stackS.pop(0)
            t = stackT.pop(0)
            
            if t and s and t.val != s.val:
                return False
            elif t and s:
                s = s.right
                t = t.right
        return True
            
