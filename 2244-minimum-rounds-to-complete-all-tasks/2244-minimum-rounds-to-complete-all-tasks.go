func minimumRounds(tasks []int) int {
    ans := 0
    cnt := make(map[int]int, len(tasks))
    for _, i := range tasks { cnt[i]++ }
    for _, c := range cnt {
        if c == 1 { return -1 }
        ans += (c+2)/3
    }
    return ans
}