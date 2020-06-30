"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if not root:
            return []
        queue = [[root, 0]]
        r = [[]]
        
        while len(queue) != 0:
            root = queue.pop(0)
            
            if len(r)-1 < root[1]:
                r.append([])
                
            r[root[1]].append(root[0].val)

            for child in root[0].children:   
                queue.append([child, root[1]+1])
                
        return r
        
