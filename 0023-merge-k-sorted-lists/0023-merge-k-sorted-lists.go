/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
    arr := make([]int, 0)
    for _, head := range lists {
        for cur := head; cur != nil; cur = cur.Next {
            arr = append(arr, cur.Val)
        }
    }
    n := len(arr)
    if n == 0 { return nil }
    slices.Sort(arr)
    ret := &ListNode{arr[0], nil}
    cur := ret
    for i := 1; i < n; i++ {
        cur.Next = &ListNode{arr[i], nil}
        cur = cur.Next
    }
    return ret
}