func maximalPathQuality(values []int, edges [][]int, maxTime int) int {
    n := len(values)
    vis := make([]int, n)
    adj := make([][][]int, n)

    for _, i := range edges {
        adj[i[0]] = append(adj[i[0]], []int{i[1], i[2]})
        adj[i[1]] = append(adj[i[1]], []int{i[0], i[2]})
    }

    ans := 0
    tmp := 0

    var dfs func(cur int, t int)
    dfs = func(cur int, t int) {
        if t > maxTime { return }
        if vis[cur] == 0 { tmp += values[cur] }
        vis[cur]++
        if cur == 0 { ans = max(ans, tmp) }

        for _, to := range adj[cur] {
            dfs(to[0], t + to[1])
        }

        vis[cur]--
        if vis[cur] == 0 { tmp -= values[cur] }
    }
    dfs(0, 0)

    return ans
}