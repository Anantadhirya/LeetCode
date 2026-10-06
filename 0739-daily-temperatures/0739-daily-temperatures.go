func dailyTemperatures(t []int) []int {
    n := len(t)
    st := make([]int, n)
    ans := make([]int, n)
    top := -1
    for i := n-1; i >= 0; i-- {
        for top != -1 && t[st[top]] <= t[i] {
            top--
        }
        if top != -1 {
            ans[i] = st[top]-i
        }
        top++
        st[top] = i
    }
    return ans
}