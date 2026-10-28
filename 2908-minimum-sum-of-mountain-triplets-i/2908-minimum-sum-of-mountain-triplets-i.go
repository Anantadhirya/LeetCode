func minimumSum(nums []int) int {
    inf := math.MaxInt
    ans := inf
    n := len(nums)
    for i := 0; i < n; i++ {
        for j := i+1; j < n; j++ {
            if nums[i] >= nums[j] { continue }
            for k := j+1; k < n; k++ {
                if nums[j] > nums[k] { ans = min(ans, nums[i] + nums[j] + nums[k]) }
            }
        }
    }

    if ans == inf { return -1 }
    return ans
}