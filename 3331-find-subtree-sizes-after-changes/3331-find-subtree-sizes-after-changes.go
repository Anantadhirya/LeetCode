func findSubtreeSizes(parent []int, s string) []int {
    n := len(parent)
    lst := make([]int, 26)
    ans := make([]int, n)
    adj := make([][]int, n)
    adj2 := make([][]int, n)
    for i := range lst { lst[i] = -1 }
    for i := 1; i < n; i++ { adj[parent[i]] = append(adj[parent[i]], i) }

    var dfs func(cur int)
    dfs = func(cur int) {
        c := int(s[cur]-'a')
        if lst[c] != -1 { parent[cur] = lst[c] }
        tmp := lst[c]
        lst[c] = cur

        for _, to := range adj[cur] {
            dfs(to)
        }

        lst[c] = tmp
    }
    dfs(0)

    for i := 1; i < n; i++ { adj2[parent[i]] = append(adj2[parent[i]], i) }
    var dfs2 func(cur int)
    dfs2 = func(cur int) {
        ans[cur] = 1
        for _, to := range adj2[cur] {
            dfs2(to)
            ans[cur] += ans[to]
        }
    }
    dfs2(0)

    return ans
}