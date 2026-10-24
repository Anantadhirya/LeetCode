func countDaysTogether(arriveAlice string, leaveAlice string, arriveBob string, leaveBob string) int {
    m := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    for i := 1; i < 12; i++ { m[i] += m[i-1] }
    
    f := func(s string) int {
        month, _ := strconv.ParseInt(s[:2], 10, 32)
        day, _ := strconv.ParseInt(s[3:], 10, 32)
        if month != 1 { return m[month-2] + int(day-1) }
        return int(day-1)
    }

    l := max(f(arriveAlice), f(arriveBob))
    r := min(f(leaveAlice), f(leaveBob))
    if l <= r { return r-l+1 }
    return 0
}