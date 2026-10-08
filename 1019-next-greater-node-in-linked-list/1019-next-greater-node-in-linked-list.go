/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nextLargerNodes(head *ListNode) []int {
    nums := make([]int, 0)
    for cur := head; cur != nil; cur = cur.Next {
        nums = append(nums, cur.Val)
    }
    n := len(nums)
    ans := make([]int, n)
    st := make([]int, n)
    top := -1
    for i := n-1; i >= 0; i-- {
        for top != -1 && st[top] <= nums[i] {
            top--
        }
        if top == -1 { ans[i] = 0 } else { ans[i] = st[top] }
        top++
        st[top] = nums[i]
    }
    return ans
}