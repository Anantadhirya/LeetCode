func minSumSquareDiff(nums1 []int, nums2 []int, k1 int, k2 int) int64 {
    n := len(nums1)
    k := k1 + k2
    for i := 0; i < n; i++ {
        nums1[i] = int(math.Abs(float64(nums1[i] - nums2[i])))
    }
    slices.Sort(nums1)
    idx := n-1
    for idx-1 >= 0 && k > 0 {
        if new_k := k - (nums1[idx] - nums1[idx-1]) * (n-idx); new_k >= 0 {
            k = new_k
            idx--
        } else { break; }
    }
    for i := idx; i < n; i++ {
        nums1[i] = nums1[idx]
    }
    cnt := n-idx
    for i := 0; i < cnt; i++ {
        nums1[n-1-i] -= k/cnt
        if i < k%cnt { nums1[n-1-i]-- }
        nums1[n-1-i] = max(nums1[n-1-i], 0)
    }
    var ans int64
    for i := 0; i < n; i++ {
        ans += int64(nums1[i]) * int64(nums1[i])
    }
    return ans
}