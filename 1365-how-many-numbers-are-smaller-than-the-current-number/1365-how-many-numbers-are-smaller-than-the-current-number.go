func smallerNumbersThanCurrent(nums []int) []int {
    n := len(nums)
    p := make([][]int, n)
    for i, v := range nums {
        p[i] = []int{v, i}
    }
    slices.SortFunc(p, slices.Compare)
    for i, j, cnt := 0, 0, 0; i < n; i = j {
        for j < n && p[j][0] == p[i][0] {
            nums[p[j][1]] = cnt
            j++
        }
        cnt += j-i
    }
    return nums
}