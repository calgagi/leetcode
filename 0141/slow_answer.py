# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        from collections import defaultdict
        map = defaultdict(int)
        while head:
            if map[head] == 1:
                return True
            map[head] = 1
            head = head.next
        return False
        
