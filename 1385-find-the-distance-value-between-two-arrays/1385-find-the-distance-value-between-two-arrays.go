func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
    ans := 0
    f := false
    for _, i := range arr1 {
        f = false
        for _, j := range arr2 {
            if max(i-j, j-i) <= d { f = true }
        }
        if !f { ans++ }
    }
    return ans
}