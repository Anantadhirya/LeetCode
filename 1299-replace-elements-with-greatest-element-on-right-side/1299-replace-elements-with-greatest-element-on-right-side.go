func replaceElements(arr []int) []int {
    n := len(arr)
    ret := make([]int, n)
    ret[n-1] = -1
    for i := n-2; i >= 0; i-- {
        ret[i] = max(ret[i+1], arr[i+1])
    }
    return ret
}