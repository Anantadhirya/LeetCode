func checkSubarraySum(nums []int, k int) bool {
    n := len(nums)
    m := make(map[int]bool)
    pref := make([]int, n+1)
    for i := 1; i <= n; i++ {
        pref[i] = (pref[i-1] + nums[i-1]) % k
        if m[pref[i]] { return true }
        m[pref[i-1]] = true
    }
    return false
}