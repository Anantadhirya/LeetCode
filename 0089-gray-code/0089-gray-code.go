func grayCode(n int) []int {
    if n == 0 { return []int{0} }
    ans := grayCode(n-1)
    for i := len(ans)-1; i >= 0; i-- {
        ans = append(ans, ans[i]+(1<<(n-1)))
    } 
    return ans
}