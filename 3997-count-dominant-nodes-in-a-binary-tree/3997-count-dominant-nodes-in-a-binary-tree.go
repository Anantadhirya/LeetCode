/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func solve(cur *TreeNode) [2]int {
    if cur == nil { return [2]int{0, 0} }
    l := solve(cur.Left)
    r := solve(cur.Right)
    mx := max(l[1], r[1], cur.Val)
    ans := l[0] + r[0]
    if cur.Val == mx { ans++ }
    return [2]int{ans, mx}
}
func countDominantNodes(root *TreeNode) int {
    return solve(root)[0]
}