func reductionOperations(nums []int) int {
    n := len(nums)
    slices.Sort(nums)
    ans := 0
    for i, j, unique := 0, 0, 0; i < n; i++ {
        for j < n && nums[j] < nums[i] { 
            j++
            if j == 0 || nums[j] != nums[j-1] { unique++ }
        }
        ans += unique
    }
    return ans
}