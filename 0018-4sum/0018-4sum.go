func fourSum(nums []int, target int) [][]int {
    n := len(nums)
    s := make(map[[4]int]struct{})
    s1 := make(map[int]struct{})
    var tmp [4]int

    for i := 0; i < n; i++ {
        for j := i+1; j < n; j++ {
            for k := j+1; k < n; k++ {
                tmp = [4]int{target-nums[i]-nums[j]-nums[k], nums[i], nums[j], nums[k]}
                if _, ok := s1[tmp[0]]; ok {
                    slices.Sort(tmp[:])
                    s[tmp] = struct{}{}
                }
            }
        }
        s1[nums[i]] = struct{}{}
    }

    ans := make([][]int, 0, len(s))
    for i := range s {
        ans = append(ans, []int{i[0], i[1], i[2], i[3]})
    }
    return ans
}