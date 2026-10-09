func solve(n int, memo map[int][]int) []int {
    if ret, ok := memo[n]; ok { return ret }
    odd := solve((n+1)/2, memo)
    even := solve(n/2, memo)

    ret := make([]int, 0, n)
    for _, i := range odd { ret = append(ret, 2*i-1) }
    for _, i := range even { ret = append(ret, 2*i) }
    memo[n] = ret
    return ret
}
func beautifulArray(n int) []int {
    memo := make(map[int][]int)
    memo[1] = []int{1}
    return solve(n, memo)
}