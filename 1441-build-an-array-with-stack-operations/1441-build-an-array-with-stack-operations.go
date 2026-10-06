func buildArray(target []int, n int) []string {
    cur := 1
    ans := make([]string, 0)
    for _, i := range target {
        for cur < i {
            cur++
            ans = append(ans, "Push", "Pop")
        }
        cur++
        ans = append(ans, "Push")
    }
    return ans
}