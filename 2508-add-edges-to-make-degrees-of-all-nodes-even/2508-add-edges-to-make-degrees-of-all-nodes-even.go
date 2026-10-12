func isPossible(n int, edges [][]int) bool {
    deg := make([]int, n)
    for _, i := range edges {
        deg[i[0]-1]++
        deg[i[1]-1]++
    }
    odd := make([]int, 0, n)
    for i := 0; i < n; i++ {
        if deg[i] % 2 == 1 {
            odd = append(odd, i)
        }
    }
    if len(odd) == 0 { return true }
    if len(odd) == 2 {
        con := make([]bool, n)
        for _, i := range edges {
            if i[0]-1 == odd[0] || i[0]-1 == odd[1] {
                con[i[1]-1] = true
            }
            if i[1]-1 == odd[0] || i[1]-1 == odd[1] {
                con[i[0]-1] = true
            }
        }
        for i := 0; i < n; i++ {
            if !con[i] { return true }
        }
        return false
    }
    if len(odd) == 4 {
        con := make([][]bool, 4)
        for i := 0; i < 4; i++ { con[i] = make([]bool, 4) }

        for _, i := range edges {
            u, v := -1, -1
            for j := 0; j < 4; j++ {
                if i[0]-1 == odd[j] { u = j }
                if i[1]-1 == odd[j] { v = j }
            }
            if u != -1 && v != -1 {
                con[u][v] = true
                con[v][u] = true
            }
        }
        for i := 0; i < 4; i++ {
            for j := i+1; j < 4; j++ {
                for k := 0; k < 4; k++ {
                    if k == i || k == j { continue }
                    for l := k+1; l < 4; l++ {
                        if l == i || l == j { continue }
                        if !con[i][j] && !con[k][l] { return true }
                    }
                }
            }
        }
        return false
    }
    return false
}