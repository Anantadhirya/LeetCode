func countIslands(grid [][]int, k int) int {
    ans := 0
    n := len(grid)
    m := len(grid[0])
    dx := []int{1, -1, 0, 0}
    dy := []int{0, 0, 1, -1}
    
    sm := 0
    var dfs func(i, j int)
    dfs = func(i, j int) {
        if i < 0 || i >= n || j < 0 || j >= m { return }
        if grid[i][j] == 0 { return }
        sm += grid[i][j]
        grid[i][j] = 0
        for d := 0; d < 4; d++ {
            dfs(i+dx[d], j+dy[d])
        }
    }
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if grid[i][j] > 0 {
                sm = 0
                dfs(i, j)
                if sm % k == 0 { ans++ }
            }
        }
    }
    return ans
}