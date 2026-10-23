func maximumEvenSplit(finalSum int64) []int64 {
    if finalSum % 2 == 1 { return []int64{} }
    ans := make([]int64, 0)
    for i := int64(2); i <= finalSum; i += 2 {
        ans = append(ans, i)
        finalSum -= i
    }
    ans[len(ans)-1] += finalSum
    return ans
}