func minimizeSet(divisor1 int, divisor2 int, uniqueCnt1 int, uniqueCnt2 int) int {
    l := int64(0)
    r := 4*(int64(uniqueCnt1) + int64(uniqueCnt2))
    mid := int64(-1)
    ans := int64(0)
    d1 := int64(divisor1)
    d2 := int64(divisor2)
    gcd := func(a, b int64) int64 {
        for b != 0 { a, b = b, a%b }
        return a
    }
    lcm := d1*d2/gcd(d1,d2)

    check := func(x int64) bool {
        cnt1 := int64(0)
        cnt2 := int64(0)
        left := x - x/lcm

        if d1 != d2 {
            cnt1 = x/d2 - x/lcm
            cnt2 = x/d1 - x/lcm
            left -= cnt1 + cnt2 
        }
        cnt1 = max(int64(0), int64(uniqueCnt1) - cnt1)
        cnt2 = max(int64(0), int64(uniqueCnt2) - cnt2)
        return left >= cnt1 + cnt2
    }
    for l <= r {
        mid = (l+r)/2
        if check(mid) {
            ans = mid
            r = mid - 1
        } else { l = mid + 1 }
    }
    return int(ans)
}