type DataStream struct {
    value, k int
    cnt int
}


func Constructor(value int, k int) DataStream {
    return DataStream{value, k, 0}
}


func (this *DataStream) Consec(num int) bool {
    if num == this.value { this.cnt++ } else { this.cnt = 0 }
    return this.cnt >= this.k
}


/**
 * Your DataStream object will be instantiated and called as such:
 * obj := Constructor(value, k);
 * param_1 := obj.Consec(num);
 */