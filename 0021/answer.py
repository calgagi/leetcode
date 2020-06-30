# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        returnList = ListNode("head")
        iterator = returnList

        while l1 != None and l2 != None:
            if l1.val > l2.val:
                iterator.next = l2
                l2 = l2.next
            else:
                iterator.next = l1
                l1 = l1.next
            iterator = iterator.next

        while l1 != None:
            iterator.next = l1
            l1 = l1.next
            iterator = iterator.next

        while l2 != None:
            iterator.next = l2
            l2 = l2.next
            iterator = iterator.next

        return returnList.next

            
