func kthLargestNumber(nums []string, k int) string {
    slices.SortFunc(nums, func(a, b string) int {
        if len(a) != len(b) { return cmp.Compare(len(a), len(b)) }
        return cmp.Compare(a, b)
    })
    return nums[len(nums)-k]
}