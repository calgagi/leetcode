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
        it = head
        count = []
        while it != None:
            count.append(it)
            it = it.next

        return count[(len(count)//2)]
