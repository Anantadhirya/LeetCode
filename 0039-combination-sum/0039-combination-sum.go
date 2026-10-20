func combinationSum(candidates []int, target int) [][]int {
    n := len(candidates)
    l := 0
    sm := 0
    ans := make([][]int, 0, 151)
    cur := make([]int, 20)

    var solve func(idx int)
    solve = func(idx int) {
        if sm > target { return }
        if sm == target {
            ans = append(ans, slices.Clone(cur[:l]))
            return
        }
        if idx >= n { return }
        
        solve(idx+1)

        l++
        cur[l-1] = candidates[idx]
        sm += candidates[idx]
        solve(idx)
        l--
        sm -= candidates[idx]
    }
    solve(0)

    return ans
}