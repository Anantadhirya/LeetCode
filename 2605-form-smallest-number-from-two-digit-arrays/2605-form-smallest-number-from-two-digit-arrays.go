func minNumber(nums1 []int, nums2 []int) int {
    for i := 1; i <= 9; i++ {
        if slices.Contains(nums1, i) && slices.Contains(nums2, i) {
            return i
        }
    }
    a := slices.Min(nums1)
    b := slices.Min(nums2)
    return min(10*a+b, 10*b+a)
}