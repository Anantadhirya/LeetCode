func maxCapacity(costs []int, capacity []int, budget int) int {
    n := len(costs)
    v := make([][]int, n)
    for i := 0; i < n; i++ { v[i] = []int{costs[i], capacity[i]} }
    slices.SortFunc(v, slices.Compare)
    ans := 0
    mx := make([]int, n)
    mx[0] = v[0][1]
    for i := 1; i < n; i++ { mx[i] = max(mx[i-1], v[i][1]) }
    for i, j := n-1, 0; i >= 0; i-- {
        if v[i][0] < budget { ans = max(ans, v[i][1]) }
        for j < n && v[j][0] + v[i][0] < budget { j++ }
        if j-1 >= 0 && i-1 >= 0 { ans = max(ans, v[i][1] + mx[min(j-1, i-1)]) }
    }
    return ans
}