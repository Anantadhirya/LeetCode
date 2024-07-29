# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        heads = [ListNode(), ListNode()]
        tails = [heads[0], heads[1]]
        p = 1
        while head:
            tails[p].next = ListNode(head.val, None)
            tails[p] = tails[p].next
            p = 1 - p
            head = head.next
        tails[1].next = heads[0].next
        return heads[1].next