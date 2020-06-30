# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        outputHead = ListNode(0)
        outputNodeCurr = outputHead
        while True:
            if l1 == None and l2 == None:
                break
            else:
                temp = carry
                if l1 != None:
                    temp += l1.val
                if l2 != None:
                    temp += l2.val
                if temp >= 10:
                    carry = 1
                else:
                    carry = 0
                outputNodeCurr.val = (temp%10)
                if l1 != None:
                    l1 = l1.next
                if l2 != None:
                    l2 = l2.next
                if l1 != None or l2 != None:
                    outputNodeCurr.next = ListNode(0)
                    outputNodeCurr = outputNodeCurr.next
        if carry == 1:
            outputNodeCurr.next = ListNode(1)
        return outputHead



        
