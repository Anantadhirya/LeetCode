func findRightInterval(intervals [][]int) []int {
    n := len(intervals)
    ans := make([]int, n)
    for i := range intervals {
        intervals[i] = append(intervals[i], i)
    }
    slices.SortFunc(intervals, slices.Compare)
    for i, idx := n-1, 0; i >= 0; i-- {
        idx = intervals[i][2]
        ans[idx] = -1
        for l, r, mid := i, n-1, 0; l <= r; {
            mid = (l+r)/2
            if intervals[i][1] <= intervals[mid][0] {
                ans[idx] = intervals[mid][2]
                r = mid-1
            } else { l = mid+1 }
        }
    }
    return ans
}