func smallestAbsent(nums []int) int {
    n := len(nums)
    sm := 0
    s := make(map[int]struct{}, n)
    for _, i := range nums { sm += i; s[i] = struct{}{} }
    for i := max(1, sm/n); ; i++ {
        if i*n <= sm { continue }
        if _, ok := s[i]; ok { continue }
        return i
    }
    return -1
}