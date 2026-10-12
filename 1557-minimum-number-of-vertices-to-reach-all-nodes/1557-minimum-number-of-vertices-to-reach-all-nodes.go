func findSmallestSetOfVertices(n int, edges [][]int) []int {
    vis := make([]bool, n)
    for _, i := range edges {
        vis[i[1]] = true
    }
    ans := make([]int, 0, n)
    for i := 0; i < n; i++ {
        if vis[i] { continue }
        ans = append(ans, i)
    }
    return ans
}