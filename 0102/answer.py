# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: 'TreeNode') -> 'List[List[int]]':
        queue = [root]
        level_queue = [0]
        r = []
        
        while len(queue) != 0:
            root = queue.pop(0)
            level = level_queue.pop(0)
            if root:
                if level == len(r):
                    r.append([])
                r[level].append(root.val)
                queue.append(root.left)
                queue.append(root.right)
                level_queue.append(level+1)
                level_queue.append(level+1)
        return r
                
            
            
        
