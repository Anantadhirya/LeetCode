func findErrorNums(nums []int) []int {
    n := len(nums)
    cnt := make([]int, n)
    for _, i := range nums {
        cnt[i-1]++
    }
    ans := make([]int, 2)
    for i := 0; i < n; i++ {
        switch cnt[i] {
            case 0:
                ans[1] = i+1
            case 2:
                ans[0] = i+1
        }
    }
    return ans
}