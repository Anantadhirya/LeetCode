type Item struct{ node, dist int }
type PQ []Item

func (h PQ) Len() int           { return len(h) }
func (h PQ) Less(i, j int) bool { return h[i].dist < h[j].dist }
func (h PQ) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *PQ) Push(x any)        { *h = append(*h, x.(Item)) }
func (h *PQ) Pop() any          { old := *h; *h = old[:len(old)-1]; return old[len(old)-1] }

func networkDelayTime(times [][]int, n int, k int) int {
    inf := math.MaxInt
    adj := make([][][2]int, n)
    vis := make([]bool, n)
    dist := make([]int, n)
    for i := 0; i < n; i++ { dist[i] = inf }
    for _, i := range times { adj[i[0]-1] = append(adj[i[0]-1], [2]int{i[1]-1, i[2]})}

    pq := &PQ{}
    heap.Init(pq)

    add := func(i, d int) {
        if d < dist[i] {
            dist[i] = d
            heap.Push(pq, Item{i, dist[i]})
        }
    }
    add(k-1, 0)
    for pq.Len() > 0 {
        cur := heap.Pop(pq).(Item).node
        if vis[cur] { continue }
        vis[cur] = true
        for _, to := range adj[cur] {
            add(to[0], dist[cur] + to[1])
        }
    }

    ans := slices.Max(dist)
    if ans == inf { return -1 }
    return ans
}