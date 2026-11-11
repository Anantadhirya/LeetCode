func minimumCost(cost1 int, cost2 int, costBoth int, need1 int, need2 int) int64 {
    c1, c2, cB, n1, n2 := int64(cost1), int64(cost2), int64(costBoth), int64(need1), int64(need2)
    n := min(n1, n2)
    return min(cB * n + c1 * (n1 - n) + c2 * (n2 - n), cB * max(n1, n2), c1 * n1 + c2 * n2)
}