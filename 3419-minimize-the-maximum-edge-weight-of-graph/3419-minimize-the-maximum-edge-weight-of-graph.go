func minMaxWeight(n int, edges [][]int, threshold int) int {
    adj := make([][][2]int, n)
    mx := 0
    for _, i := range edges {
        adj[i[1]] = append(adj[i[1]], [2]int{i[0], i[2]})
        mx = max(mx, i[2])
    }

    vis := make([]bool, n)
    var dfs func(cur int, x int)
    dfs = func(cur int, x int) {
        if vis[cur] { return }
        vis[cur] = true
        for _, to := range adj[cur] {
            if to[1] > x { continue }
            dfs(to[0], x)
        }
    }
    check := func(x int) bool {
        for i := 0; i < n; i++ { vis[i] = false }
        dfs(0, x)
        for i := 0; i < n; i++ {
            if !vis[i] { return false }
        }
        return true
    }

    ans := -1
    for l, r, mid := 0, mx, 0; l <= r; {
        mid = (l+r)/2
        if check(mid) {
            ans = mid
            r = mid - 1
        } else { l = mid + 1 }
    }
    return ans
}