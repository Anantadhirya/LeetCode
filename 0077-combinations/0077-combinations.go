func combine(n int, k int) [][]int {
    ans := make([][]int, 0)
    cur := make([]int, k)
    idx := 0

    var solve func(i int);
    solve = func(i int) {
        if i == n+1 || idx == k {
            if idx == k { ans = append(ans, append([]int{}, cur...)) }
            return
        }
        // i is not chosen
        solve(i+1)

        // i is chosen
        cur[idx] = i
        idx++
        solve(i+1)
        idx--
    }

    solve(1)
    return ans
}