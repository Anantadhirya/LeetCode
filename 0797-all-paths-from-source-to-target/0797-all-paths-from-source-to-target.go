func allPathsSourceTarget(graph [][]int) [][]int {
    n := len(graph)
    path := make([]int, n+5)
    sz := 0
    ans := make([][]int, 0)

    var dfs func(cur int)
    dfs = func(cur int) {
        path[sz] = cur
        sz++

        if cur == n-1 {
            ans = append(ans, slices.Clone(path[:sz]))
        }

        for _, to := range graph[cur] {
            dfs(to)
        }
        sz--
    }
    dfs(0)

    return ans
}