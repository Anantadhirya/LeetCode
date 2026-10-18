func sumOfBeauties(nums []int) int {
    n := len(nums)
    pref := make([]int, n)
    suff := make([]int, n)
    pref[0] = nums[0]
    for i := 1; i < n; i++ {
        pref[i] = max(pref[i-1], nums[i])
    }
    suff[n-1] = nums[n-1]
    for i := n-2; i >= 0; i-- {
        suff[i] = min(suff[i+1], nums[i])
    }
    ans := 0
    for i := 1; i <= n-2; i++ {
        if pref[i-1] < nums[i] && nums[i] < suff[i+1] {
            ans += 2
        } else if nums[i-1] < nums[i] && nums[i] < nums[i+1] {
            ans += 1
        }
    }
    return ans
}