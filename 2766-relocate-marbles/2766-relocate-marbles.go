func relocateMarbles(nums []int, moveFrom []int, moveTo []int) []int {
    s := make(map[int]struct{}, len(nums))

    for _, i := range nums {
        s[i] = struct{}{}
    }

    for i := range moveFrom {
        if _, ok := s[moveFrom[i]]; ok {
            delete(s, moveFrom[i])
            s[moveTo[i]] = struct{}{} 
        }
    }

    ans := make([]int, 0, len(s))
    for i := range s {
        ans = append(ans, i)
    }
    slices.Sort(ans)
    return ans
}