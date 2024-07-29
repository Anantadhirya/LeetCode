# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        v = []
        while head:
            v.append(head.val)
            head = head.next
        n = len(v)
        return max([v[i] + v[n-1-i] for i in range(n//2)])