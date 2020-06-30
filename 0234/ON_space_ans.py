# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        l = []
        while head:
            l.append(head.val)
            head = head.next
        
        begin, end = 0, len(l)-1
        while begin < end:
            if l[begin] != l[end]:
                return False
            begin += 1
            end -= 1
        return True
