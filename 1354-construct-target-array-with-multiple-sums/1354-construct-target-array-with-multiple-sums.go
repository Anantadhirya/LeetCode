type H []int

func (h H) Len() int           { return len(h) }
func (h H) Less(i, j int) bool { return h[i] > h[j] }
func (h H) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *H) Push(x any)        { *h = append(*h, x.(int)) }
func (h *H) Pop() any          { x := (*h)[len(*h)-1]; *h = (*h)[:len(*h)-1]; return x }
func (h H) Top() int           { return h[0] }

func isPossible(target []int) bool {
    if len(target) == 1 { return target[0] == 1 }
    sm := 0
    for _, i := range target { sm += i }
    
    h := (*H)(&target)
    heap.Init(h)
    
    for {
        top := heap.Pop(h).(int)
        if top == 1 { return true }
        sm -= top
        prev := top - max(1, top/sm - 1) * sm
        if prev < 1 { return false }
        heap.Push(h, prev)
        sm += prev
    }
    return false
}