func exclusiveTime(n int, logs []string) []int {
    ans := make([]int, n)
    st := make([]int, len(logs))
    top := -1
    cur := 0
    for _, i := range logs {
        s := strings.Split(i, ":")
        id, _ := strconv.Atoi(s[0])
        tp := s[1]
        t, _ := strconv.Atoi(s[2])
        if top != -1 {
            ans[st[top]] += t - cur
        }
        cur = t
        if tp == "start" {
            top++
            st[top] = id
        } else {
            ans[st[top]]++
            cur++
            top--
        }
    }
    return ans
}