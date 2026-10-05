func shuffle(nums []int, n int) []int {
    ret := make([]int, 2*n)
    for i := 0; i < n; i++ {
        ret[2*i] = nums[i]
        ret[2*i+1] = nums[n+i]
    }
    return ret
}