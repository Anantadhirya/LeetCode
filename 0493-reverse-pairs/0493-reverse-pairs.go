func reversePairs(nums []int) int {
    n := len(nums)
    arr := make([][]int, n)
    for i, x := range nums {
        arr[i] = []int{x, i}
    }
    slices.SortFunc(arr, slices.Compare)
    
    // Fenwick Tree
    ft := make([]int, n)
    update := func(idx int, val int) {
        for i := idx+1; i <= n; i += i&-i {
            ft[i-1] += val
        }
    }
    query := func(idx int) int {
        ret := 0
        for i := idx+1; i > 0; i -= i&-i {
            ret += ft[i-1]
        }
        return ret
    }

    // Solve
    ans := 0
    for i, j := 0, 0; i < n; i++ {
        for j < n && 2*arr[j][0] < arr[i][0] { update(arr[j][1], 1); j++ }
        ans += query(n-1) - query(arr[i][1])
    }
    return ans
}