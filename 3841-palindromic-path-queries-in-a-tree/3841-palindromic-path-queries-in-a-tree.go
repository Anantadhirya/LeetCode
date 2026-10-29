func palindromePath(n int, edges [][]int, s string, queries []string) []bool {
    // LCA
    lg := 16
    t := -1
    tin := make([]int, n)
    tout := make([]int, n)
    up := make([][]int, n)
    for i := 0; i < n; i++ { up[i] = make([]int, lg+1) }
    isanc := func(a, b int) bool {
        return tin[a] <= tin[b] && tout[b] <= tout[a]
    }
    lca := func(a, b int) int {
        if isanc(a, b) { return a }
        if isanc(b, a) { return b }
        for i := lg; i >= 0; i-- {
            if !isanc(up[a][i], b) { a = up[a][i] }
        }
        return up[a][0]
    }
    
    // Fenwick Tree
    ft := make([]int, n)
    point_update := func(idx int, val int) {
        for i := idx+1; i <= n; i += i&-i {
            ft[i-1] ^= val
        }
    }
    update := func(l int, r int, val int) {
        point_update(l, val)
        point_update(r+1, val)
    }
    query := func(idx int) int {
        ret := 0
        for i := idx+1; i > 0; i -= i&-i {
            ret ^= ft[i-1]
        }
        return ret
    }

    arr := []rune(s)
    adj := make([][]int, n)
    for _, i := range edges {
        adj[i[0]] = append(adj[i[0]], i[1])
        adj[i[1]] = append(adj[i[1]], i[0])
    }
    var dfs func(cur int, from int, val int)
    dfs = func(cur int, from int, val int) {
        t++
        tin[cur] = t
        up[cur][0] = from
        for i := 1; i <= lg; i++ { up[cur][i] = up[up[cur][i-1]][i-1] }

        val = val ^ (1<<(arr[cur]-'a'))
        update(tin[cur], tin[cur], val)

        for _, to := range adj[cur] {
            if to == from { continue }
            dfs(to, cur, val)
        }
        tout[cur] = t
    }
    dfs(0, 0, 0)

    ans := make([]bool, 0, len(queries))
    for _, tmp := range queries {
        q := strings.Split(tmp, " ")
        if q[0] == "update" {
            u, _ := strconv.Atoi(q[1])
            c := q[2][0]
            update(tin[u], tout[u], (1<<(arr[u]-'a')) ^ (1<<(c-'a')))
            arr[u] = rune(c)
        } else if q[0] == "query" {
            u, _ := strconv.Atoi(q[1])
            v, _ := strconv.Atoi(q[2])
            val := query(tin[u]) ^ query(tin[v]) ^ (1<<(arr[lca(u,v)]-'a'))
            ans = append(ans, bits.OnesCount(uint(val)) <= 1)
        }
    }
    return ans
}