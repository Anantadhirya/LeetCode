func maximumSaleItems(items [][]int, budget int) int {
    n := len(items)
    cnt := make([]int, n+1)
    w := make([]int, n+1)
    for _, i := range items { cnt[i[0]]++ }
    for i := 1; i <= n; i++ {
        for j := i; j <= n; j += i {
            w[i] += cnt[j]
        }
    }
    mn := items[0][1]
    for i := range items {
        mn = min(mn, items[i][1])
        items[i][0], items[i][1] = items[i][1], w[items[i][0]]-1
    }
    slices.SortFunc(items, slices.Compare)
    ans := budget/mn
    tmp := 0
    x := 0
    for i := 0; i < n; i++ {
        if items[i][0] >= 2*mn { continue }
        x = min(items[i][1], budget/items[i][0])
        tmp += 2*x
        budget -= x*items[i][0]
        ans = max(ans, tmp + budget/mn)
    }
    return ans
}