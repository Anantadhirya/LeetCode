func matrixBlockSum(mat [][]int, k int) [][]int {
    n := len(mat)
    m := len(mat[0])
    pref := make([][]int, n+1)
    pref[0] = make([]int, m+1)
    for i := 1; i <= n; i++ {
        pref[i] = make([]int, m+1)
        for j := 1; j <= m; j++ {
            pref[i][j] = mat[i-1][j-1] + pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1]
        }
    }
    var li, ri, lj, rj int
    for i := 1; i <= n; i++ {
        for j := 1; j <= m; j++ {
            li = max(1, i-k)
            ri = min(n, i+k)
            lj = max(1, j-k)
            rj = min(m, j+k)
            mat[i-1][j-1] = pref[ri][rj] - pref[li-1][rj] - pref[ri][lj-1] + pref[li-1][lj-1]
        }
    }
    return mat
}