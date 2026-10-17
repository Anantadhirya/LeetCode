/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sliceToBST(arr []int) *TreeNode {
    n := len(arr)
    if n == 0 { return nil }
    return &TreeNode{arr[n/2], sliceToBST(arr[:n/2]), sliceToBST(arr[n/2+1:])}
}
func sortedListToBST(head *ListNode) *TreeNode {
    arr := make([]int, 0)
    for cur := head; cur != nil; cur = cur.Next {
        arr = append(arr, cur.Val)
    }
    return sliceToBST(arr)
}