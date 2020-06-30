# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        itA, itB = headA, headB
        while itA != itB:
            if itA == None:
                itA = headB
            else:
                itA = itA.next
            if itB == None:
                itB = headA
            else:
                itB = itB.next
        return itA
            
        
