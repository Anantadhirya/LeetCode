func friendRequests(n int, restrictions [][]int, requests [][]int) []bool {
    par := make([]int, n)
    sz := make([]int, n)
    for i := 0; i < n; i++ { par[i] = i; sz[i] = 1 }

    rollback_par := make([]int, 2)
    rollback_sz := make([]int, 2)
    fp := func(i int) int {
        for i != par[i] { i = par[i] }
        return i
    }
    check := func(u, v int) bool {
        u = fp(u)
        v = fp(v)
        return u == v
    }
    join := func(u, v int) {
        u = fp(u)
        v = fp(v)
        if sz[u] > sz[v] { u, v = v, u }
        if u != v {
            rollback_par = []int{u, par[u]}
            rollback_sz = []int{v, sz[v]}
            par[u] = v
            sz[v] += sz[u]
        }
    }
    rollback := func() {
        par[rollback_par[0]] = rollback_par[1]
        sz[rollback_sz[0]] = rollback_sz[1]
    }

    ans := make([]bool, len(requests))
    for i := range requests {
        join(requests[i][0], requests[i][1])
        ans[i] = true
        for _, j := range restrictions {
            if check(j[0], j[1]) { ans[i] = false; break }
        }
        if ans[i] == false { rollback() }
    }
    return ans
}