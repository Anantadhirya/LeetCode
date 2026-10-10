func magicalString(n int) int {
    s := make([]int, n+5)
    s[0] = 1
    s[1] = 2
    s[2] = 2
    for i, j := 3, 2; i < n;  {
        if s[j] == 1 {
            s[i] = (3-s[i-1])
            i++
        } else {
            s[i] = (3-s[i-1])
            s[i+1] = (3-s[i-1])
            i += 2
        }
        j++
    }
    ans := 0
    for i := 0; i < n; i++ { 
        if s[i] == 1 { ans++ }
    }
    return ans
}