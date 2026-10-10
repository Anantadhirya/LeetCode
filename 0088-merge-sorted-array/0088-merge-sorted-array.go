func merge(nums []int, m int, nums2 []int, n int)  {
    nums1 := make([]int, m)
    for i := 0; i < m; i++ { nums1[i] = nums[i] }
    for i, use1 := 0, false; i < m+n; i++ {
        switch {
            case len(nums1) == 0: use1 = false
            case len(nums2) == 0: use1 = true
            case nums1[0] <= nums2[0]: use1 = true
            default: use1 = false
        }
        if use1 {
            nums[i] = nums1[0]; nums1 = nums1[1:]
        } else {
            nums[i] = nums2[0]; nums2 = nums2[1:]
        }
    }
    return
}