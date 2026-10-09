func search(nums []int, target int) int {
    n := len(nums)
    for l, r, mid := 0, n-1, 0; l <= r; {
        mid = (l+r)/2
        if nums[mid] == target {
            return mid
        } else if nums[mid] < target {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return -1
}