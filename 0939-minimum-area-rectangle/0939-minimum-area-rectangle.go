func minAreaRect(points [][]int) int {
    n := len(points)
    m := make(map[[2]int]struct{}, n)
    for _, i := range points {
        m[[2]int{i[0], i[1]}] = struct{}{}
    }
    inf := math.MaxInt
    ans := inf
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            if j == i { continue }
            if !(points[i][0] == points[j][0] && points[i][1] <= points[j][1]) { continue }
            for k := 0; k < n; k++ {
                if k == i || k == j { continue }
                if !(points[i][1] == points[k][1] && points[i][0] <= points[k][0]) { continue }
                if _, ok := m[[2]int{points[k][0], points[j][1]}]; ok {
                    ans = min(ans, (points[j][1] - points[i][1]) * (points[k][0] - points[i][0]))
                }
            }
        }
    }
    if ans == inf { return 0 }
    return ans
}