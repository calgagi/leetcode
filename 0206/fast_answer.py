# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head):
        prev = None # Set Previous to null
        while head: # While head is not none
            cur = head # Current gets head
            head = head.next # Head gets head's next element
            cur.next = prev # Head.next gets previous item
            prev = cur # Set previous to head (head's next element)
        return prev
