func largestRectangleArea(h []int) int {
    n := len(h)
    st := make([]int, n+1)
    top := -1
    ans := 0

    h = append(h, 0)
    for i := 0; i <= n; i++ {
        for top != -1 && h[st[top]] > h[i] {
            if top-1 != -1 { 
                ans = max(ans, h[st[top]] * (i-st[top-1]-1))
            } else {
                ans = max(ans, h[st[top]] * (i-0))
            }
            top--
        }
        top++
        st[top] = i
    }
    return ans
}