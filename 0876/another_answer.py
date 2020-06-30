# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        it_f, it_s = head, head
        while it_s and it_f and it_f.next:
            it_s = it_s.next
            it_f = it_f.next.next

        return it_s
