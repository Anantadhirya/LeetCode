type Item struct{ node int; dist int64 }
type PQ []Item

func (h PQ) Len() int           { return len(h) }
func (h PQ) Less(i, j int) bool { return h[i].dist < h[j].dist }
func (h PQ) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *PQ) Push(x any)        { *h = append(*h, x.(Item)) }
func (h *PQ) Pop() any          { old := *h; *h = old[:len(old)-1]; return old[len(old)-1] }

func minimumWeight(n int, edges [][]int, src1 int, src2 int, dest int) int64 {
    inf := int64(math.MaxInt64)
    adj := make([][][2]int, n)
    radj := make([][][2]int, n)
    for _, i := range edges {
        adj[i[0]] = append(adj[i[0]], [2]int{i[1], i[2]})
        radj[i[1]] = append(radj[i[1]], [2]int{i[0], i[2]})
    }

    dijkstra := func(s int, adj [][][2]int) []int64 {
        vis := make([]bool, n)
        dist := make([]int64, n)
        for i := 0; i < n; i++ { dist[i] = inf }
        pq := &PQ{}
        heap.Init(pq)

        add := func(i int, d int64) {
            if d < dist[i] {
                dist[i] = d
                heap.Push(pq, Item{i, dist[i]})
            }
        }

        add(s, 0)
        for pq.Len() > 0 {
            cur := heap.Pop(pq).(Item).node
            if vis[cur] { continue }
            vis[cur] = true
            for _, to := range adj[cur] {
                add(to[0], dist[cur] + int64(to[1]))
            }
        }

        return dist
    }

    d1 := dijkstra(src1, adj)
    d2 := dijkstra(src2, adj)
    dt := dijkstra(dest, radj)

    ans := inf
    if d1[dest] != inf && d2[dest] != inf { ans = min(ans, d1[dest] + d2[dest]) }
    for i := 0; i < n; i++ {
        if d1[i] != inf && d2[i] != inf && dt[i] != inf {
            ans = min(ans, d1[i] + d2[i] + dt[i])
        }
    }
    if ans == inf { return -1 }
    return ans
}