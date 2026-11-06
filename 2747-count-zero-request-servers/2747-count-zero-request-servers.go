func countServers(n int, logs [][]int, x int, queries []int) []int {
    q := len(queries)
    m := len(logs)
    v := make([][]int, q)
    ans := make([]int, q)
    
    f := make([]int, n+1)
    cnt := 0
    
    for i := 0; i < q; i++ { v[i] = []int{queries[i], i} }
    slices.SortFunc(v, slices.Compare)
    slices.SortFunc(logs, func(a, b []int) int { return cmp.Compare(a[1], b[1]) })

    for i, j, k := 0, 0, 0; i < q; i++ {
        for k < m && logs[k][1] <= v[i][0] {
            f[logs[k][0]]++
            if f[logs[k][0]] == 1 { cnt++ }
            k++
        }
        for j < m && logs[j][1] < v[i][0] - x {
            f[logs[j][0]]--
            if f[logs[j][0]] == 0 { cnt-- }
            j++
        }
        ans[v[i][1]] = n - cnt
    }
    return ans
}