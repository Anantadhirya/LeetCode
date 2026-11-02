type RangeFreqQuery struct {
    m map[int][]int
}


func Constructor(arr []int) (this RangeFreqQuery) {
    this.m = make(map[int][]int, len(arr))
    for i := range arr {
        this.m[arr[i]] = append(this.m[arr[i]], i)
    }
    return this
}


func (this *RangeFreqQuery) Query(left int, right int, value int) int {
    v := this.m[value]
    if len(v) == 0 { return 0 }
    idx1 := len(v)
    idx2 := len(v)
    l, r, mid := 0, len(v)-1, 0
    for l <= r {
        mid = (l+r)/2
        if v[mid] >= left {
            idx1 = mid
            r = mid - 1
        } else { l = mid + 1 }
    }
    l, r, mid = 0, len(v)-1, 0
    for l <= r {
        mid = (l+r)/2
        if v[mid] > right {
            idx2 = mid
            r = mid - 1
        } else { l = mid + 1 }
    }
    return idx2 - idx1
}


/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * obj := Constructor(arr);
 * param_1 := obj.Query(left,right,value);
 */