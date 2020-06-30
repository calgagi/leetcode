# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next or not head.next.next:
            if head and head.next and head.next == head:
                return head
            else:
                return None
        hare, tortoise = head.next.next, head.next
        while hare != tortoise:
            if not hare or not hare.next:
                return None
            hare = hare.next.next
            tortoise = tortoise.next
        
        hare = head
        while hare != tortoise:
            hare = hare.next
            tortoise = tortoise.next
        return hare
        
        
