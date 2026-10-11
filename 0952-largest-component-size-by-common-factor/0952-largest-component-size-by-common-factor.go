func largestComponentSize(nums []int) int {
    mx := slices.Max(nums)
    if mx < 2 { return 1 }
    primes := make([]int, 0)
    vis := make([]bool, mx+1)
    id := make([]int, mx+1)
    for i := 0; i <= mx; i++ { id[i] = -1 }
    for i := 2; i <= mx; i++ {
        if vis[i] { continue }
        primes = append(primes, i)
        for j := i*i; j <= mx; j += i { vis[j] = true }
    }

    n := len(nums)
    par := make([]int, n)
    sz := make([]int, n)
    for i := 0; i < n; i++ { par[i] = i; sz[i] = 1 }
    var fp func(i int) int
    fp = func(i int) int {
        if par[i] == i { return i }
        par[i] = fp(par[i])
        return par[i]
    }
    join := func(u int, v int) {
        if u == -1 || v == -1 { return }
        u = fp(u)
        v = fp(v)
        if u != v {
            par[u] = v
            sz[v] += sz[u]
            sz[u] = 0
        }
    }

    f := func(i int, fac int) {
        if fac == 1 { return }
        join(i, id[fac])
        id[fac] = i
    }

    for i, x := range nums {
        for j := 0; primes[j]*primes[j] <= x; j++ {
            if x % primes[j] == 0 {
                f(i, primes[j])
                for x % primes[j] == 0 {
                    x /= primes[j]
                }
            }
        }
        f(i, x)
    }
    ans := 0
    for i := range nums {
        ans = max(ans, sz[fp(i)])
    }
    return ans
}