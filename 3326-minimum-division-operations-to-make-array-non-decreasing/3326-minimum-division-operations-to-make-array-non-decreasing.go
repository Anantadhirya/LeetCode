func minOperations(nums []int) int {
    mx := slices.Max(nums)
    d := make([]int, mx+1)
    ans := 0
    for i := 2; i <= mx; i++ {
        if d[i] != 0 { continue }
        for j := i*i; j <= mx; j += i {
            if d[j] == 0 { d[j] = i }
        }
    }
    for i := len(nums)-2; i >= 0; i-- {
        for nums[i] > nums[i+1] && d[nums[i]] != 0 { nums[i] = d[nums[i]]; ans++ }
        if nums[i] > nums[i+1] { return -1 }
    }
    return ans
}