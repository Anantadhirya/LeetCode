func isPathCrossing(path string) bool {
    vis := make(map[[2]int]struct{}, len(path))
    x := 0
    y := 0
    vis[[2]int{x,y}] = struct{}{}
    for _, i := range path {
        switch i {
            case 'N': y++
            case 'S': y--
            case 'E': x++
            case 'W': x--
        }
        if _, ok := vis[[2]int{x,y}]; ok { return true }
        vis[[2]int{x,y}] = struct{}{}
    }
    return false
}