func searchInsert(nums []int, target int) int {
    n := len(nums)
    ret := n
    for l, r, mid := 0, n-1, 0; l <= r; {
        mid = (l+r)/2
        if nums[mid] >= target {
            ret = mid
            r = mid - 1
        } else { l = mid + 1 }
    }
    return ret
}