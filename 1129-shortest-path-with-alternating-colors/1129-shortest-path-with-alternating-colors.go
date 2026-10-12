func shortestAlternatingPaths(n int, redEdges [][]int, blueEdges [][]int) []int {
    adj := make([][][]int, n)
    for _, i := range redEdges {
        adj[i[0]] = append(adj[i[0]], []int{i[1], 0})
    }
    for _, i := range blueEdges {
        adj[i[0]] = append(adj[i[0]], []int{i[1], 1})
    }

    inf := math.MaxInt
    vis := make([][]bool, n)
    dist := make([][]int, n)
    ans := make([]int, n)
    for i := 0; i < n; i++ { vis[i] = make([]bool, 2); dist[i] = []int{inf, inf} }

    q := make([][]int, 0, 2*n+5)
    q = append(q, []int{0, -1})
    var cur []int
    for len(q) > 0 {
        cur = q[0]
        q = q[1:]

        cur_dist := 0
        if cur[1] != -1 { cur_dist = dist[cur[0]][cur[1]] }

        for _, to := range adj[cur[0]] {
            if to[1] == cur[1] { continue }
            if vis[to[0]][to[1]] { continue }
            vis[to[0]][to[1]] = true
            dist[to[0]][to[1]] = cur_dist + 1
            q = append(q, to)
        }
    }

    for i := 1; i < n; i++ {
        ans[i] = min(dist[i][0], dist[i][1])
        if ans[i] == inf { ans[i] = -1 }
    }
    return ans
}