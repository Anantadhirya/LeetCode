# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        v = []
        while head:
            v.append(head.val)
            head = head.next
        v.pop(len(v) // 2)
        ans = None
        while v:
            ans = ListNode(v[-1], ans)
            v.pop()
        return ans