func sortableIntegers(nums []int) int {
    n := len(nums)
    inf := math.MaxInt
    pref := make([]int, n+2)
    suff := make([]int, n+2)
    pref2 := make([]int, n+2)

    for i := 1; i <= n; i++ {
        pref[i] = max(pref[i-1], nums[i-1])
    }
    suff[n+1] = inf
    for i := n; i >= 1; i-- {
        suff[i] = min(suff[i+1], nums[i-1])
    }
    for i := 1; i+1 <= n; i++ {
        pref2[i] = pref2[i-1]
        if nums[i-1] > nums[i] { pref2[i]++ }
    }
    
    check := func(k int) bool {
        for i := 1; i+k-1 <= n; i += k {
            if pref[i+k-1] > suff[i+k] { return false }
            cnt := pref2[i+k-2] - pref2[i-1]
            if nums[i+k-1 - 1] > nums[i - 1] { cnt++ }
            if cnt > 1 { return false }
        }
        return true
    };
    ans := 0
    for i := 1; i*i <= n; i++ {
        if n % i == 0 {
            if check(i) { ans += i }
            if i != n/i && check(n/i) { ans += n/i }
        }
    }
    return ans
}