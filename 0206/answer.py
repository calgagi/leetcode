# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return
        it = head
        a = []
        while it.next != None:
            a.append(it)
            it = it.next
        a.append(it)
        for i in range(len(a)-1):
            a[i+1].next = a[i]
        a[0].next = None
        return a[len(a)-1]
        
