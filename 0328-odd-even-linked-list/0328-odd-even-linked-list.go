/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if head == nil { return head }
    if head.Next == nil { return head }
    head2 := head.Next
    cur := head
    cur2 := head2
    for i, j := head.Next.Next, 0; i != nil; i, j = i.Next, j+1 {
        if j % 2 == 0 {
            cur.Next = i
            cur = cur.Next
        } else {
            cur2.Next = i
            cur2 = cur2.Next
        }
    }
    cur.Next = head2
    cur2.Next = nil
    return head
}