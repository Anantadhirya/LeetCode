type H []int

func (h H) Len() int           { return len(h) }
func (h H) Less(i, j int) bool { return h[i] > h[j] }
func (h H) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *H) Push(x any)        { *h = append(*h, x.(int)) }
func (h *H) Pop() any          { x := (*h)[len(*h)-1]; *h = (*h)[:len(*h)-1]; return x }

func lastStoneWeight(stones []int) int {
    h := &H{}
    heap.Init(h)
    for _, i := range stones {
        heap.Push(h, i)
    }
    for h.Len() > 1 {
        x := heap.Pop(h).(int)
        y := heap.Pop(h).(int)
        if x != y {
            heap.Push(h, x-y)
        }
    }
    if h.Len() == 0 { return 0 }
    return heap.Pop(h).(int)
}