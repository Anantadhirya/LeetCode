func sortByReflection(nums []int) []int {
    reflect := func(x int) int {
        ret := 0
        for x > 0 {
            ret = (ret<<1) + (x&1)
            x >>= 1
        }
        return ret
    }

    slices.SortFunc(nums, func(a, b int) int {
        return cmp.Or(cmp.Compare(reflect(a), reflect(b)), cmp.Compare(a, b))
    })
    
    return nums
}