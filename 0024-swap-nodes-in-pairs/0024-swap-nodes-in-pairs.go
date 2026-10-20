/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    if head == nil || head.Next == nil { return head }
    ret := head.Next
    ret.Next, head.Next = head, swapPairs(ret.Next)
    return ret
}