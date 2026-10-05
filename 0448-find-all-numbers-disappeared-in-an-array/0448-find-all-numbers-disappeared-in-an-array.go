func findDisappearedNumbers(nums []int) []int {
    n := len(nums)
    ret := make([]int, 0)
    ada := make([]bool, n)
    for _, i := range nums {
        ada[i-1] = true
    }
    for i := 0; i < n; i++ {
        if !ada[i] { ret = append(ret, i+1) }
    }
    return ret
}