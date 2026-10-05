func findMaxConsecutiveOnes(nums []int) int {
    mx := 0
    cur := 0
    for _, i := range nums {
        if i == 0 {
            cur = 0
        } else {
            cur++
        }
        mx = max(mx, cur)
    }
    return mx
}