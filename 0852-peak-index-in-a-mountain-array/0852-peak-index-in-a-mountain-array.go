func peakIndexInMountainArray(arr []int) int {
    n := len(arr)
    ans := 0
    for l, r, mid := 1, n-1, 0; l <= r; {
        mid = (l+r)/2
        if arr[mid-1] <= arr[mid] {
            ans = mid
            l = mid + 1
        } else { r = mid - 1 }
    }
    return ans
}