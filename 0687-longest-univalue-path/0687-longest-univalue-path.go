/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestUnivaluePath(root *TreeNode) int {
    if root == nil { return 0 }
    ans := 0
    var solve func(cur *TreeNode) int
    solve = func(cur *TreeNode) int {
        if cur == nil { return 0 }
        tmp := 1
        l := solve(cur.Left)
        r := solve(cur.Right)
        if cur.Left == nil || cur.Val != cur.Left.Val { l = 0 }
        if cur.Right == nil || cur.Val != cur.Right.Val { r = 0 }
        ans = max(ans, tmp+l+r)
        return tmp + max(l, r)
    }
    solve(root)
    return ans-1
}