/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func insertionSortList(head *ListNode) *ListNode {
    arr := make([]int, 0)
    for cur := head; cur != nil; cur = cur.Next { arr = append(arr, cur.Val) }
    slices.Sort(arr)
    for cur, i := head, 0; cur != nil; cur = cur.Next { cur.Val = arr[i]; i++ }
    return head
}