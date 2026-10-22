func sumOddLengthSubarrays(arr []int) int {
    n := len(arr)
    ans := 0
    sm := 0
    for r := 0; r < n; r++ {
        sm = 0
        for l := r; l >= 0; l-- {
            sm += arr[l]
            if (r-l+1) % 2 == 1 { ans += sm }
        }
    }
    return ans
}