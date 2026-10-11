func restoreIpAddresses(s string) []string {
    ans := make([]string, 0)
    cur := make([]string, 4)
    n := len(s)

    check := func() bool {
        for _, i := range cur {
            num, _ := strconv.Atoi(i)
            if !(0 <= num && num <= 255) { return false }
            if i[0] == '0' && len(i) != 1 { return false }
        }
        return true
    }

    for i := 1; i < n && i <= 3; i++ {
        for j := i+1; j < n && j <= i+3; j++ {
            for k := j+1; k < n && k <= j+3; k++ {
                if n-k > 3 { continue }
                cur[0] = s[0:i]
                cur[1] = s[i:j]
                cur[2] = s[j:k]
                cur[3] = s[k:]
                if check() {
                    ans = append(ans, strings.Join(cur, "."))
                }
            }
        }
    }

    return ans
}