func validPath(n int, edges [][]int, source int, destination int) bool {
    par := make([]int, n)
    for i := 0; i < n; i++ { par[i] = i }

    var fp func(i int) int
    fp = func(i int) int {
        if par[i] == i { return i }
        par[i] = fp(par[i])
        return par[i]
    }
    join := func(u, v int) {
        u = fp(u); v = fp(v)
        par[u] = v
    }

    for _, i := range edges {
        join(i[0], i[1])
    }

    return fp(source) == fp(destination)
}