func plusOne(digits []int) []int {
    n := len(digits)
    digits[n-1]++
    for i := n-1; i >= 1 && digits[i] > 9; i-- {
        digits[i] -= 10
        digits[i-1]++
    }
    if digits[0] > 9 {
        digits[0] -= 10
        digits = slices.Insert(digits, 0, 1)
    }
    return digits
}