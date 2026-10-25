func closedIsland(grid [][]int) int {
    n := len(grid)
    m := len(grid[0])
    dx := []int{1, -1, 0, 0}
    dy := []int{0, 0, 1, -1}

    var dfs func(i, j int)
    dfs = func(i, j int) {
        if i < 0 || i >= n || j < 0 || j >= m { return }
        if grid[i][j] == 1 { return }
        grid[i][j] = 1
        for d := 0; d < 4; d++ {
            dfs(i+dx[d], j+dy[d])
        }
    }
    for i := 0; i < n; i++ {
        dfs(i, 0)
        dfs(i, m-1)
    }
    for j := 0; j < m; j++ {
        dfs(0, j)
        dfs(n-1, j)
    }
    ans := 0
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            if grid[i][j] == 0 {
                dfs(i, j)
                ans++
            }
        }
    }
    return ans
}