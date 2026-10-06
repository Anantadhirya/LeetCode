func finalPrices(prices []int) []int {
    n := len(prices)
    st := make([]int, n)
    top := 0

    for i := n-1; i >= 0; i-- {
        for top != -1 && st[top] > prices[i] {
            top--
        }
        top++
        st[top] = prices[i]
        if top - 1 != -1 {
            prices[i] -= st[top-1]
        }
    }
    return prices
}