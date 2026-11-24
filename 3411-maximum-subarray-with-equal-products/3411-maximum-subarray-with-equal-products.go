func maxLength(nums []int) int {
    n := len(nums)
    ans := 0
    f := func(a, b int) int {
        for a != 0 {
            a, b = b%a, a
        }
        return b
    }
    prod, lcm, gcd := 0, 0, 0
    for l := 0; l < n; l++ {
        prod = 1
        lcm = 1
        gcd = 0
        for r := l; r < n; r++ {
            prod = prod * nums[r]
            gcd = f(gcd, nums[r])
            lcm = lcm * nums[r] / f(lcm, nums[r])
            if prod == lcm * gcd { ans = max(ans, r-l+1) }
            if prod > 1e6 { break }
        }
    }
    return ans
}