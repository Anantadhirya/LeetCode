func filterRestaurants(restaurants [][]int, veganFriendly int, maxPrice int, maxDistance int) []int {
    ans := make([]int, 0, len(restaurants))
    slices.SortFunc(restaurants, func(a, b []int) int {
        return cmp.Or(cmp.Compare(b[1], a[1]), cmp.Compare(b[0], a[0]))
    })
    for _, i := range restaurants {
        if i[2] >= veganFriendly && i[3] <= maxPrice && i[4] <= maxDistance {
            ans = append(ans, i[0])
        }
    }
    return ans
}