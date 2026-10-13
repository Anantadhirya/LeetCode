type Item struct{ node, dist int }
type PQ []Item

func (h PQ) Len() int           { return len(h) }
func (h PQ) Less(i, j int) bool { return h[i].dist < h[j].dist }
func (h PQ) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *PQ) Push(x any)        { *h = append(*h, x.(Item)) }
func (h *PQ) Pop() any          { old := *h; *h = old[:len(old)-1]; return old[len(old)-1] }

func findTheCity(n int, edges [][]int, distanceThreshold int) int {
    adj := make([][][2]int, n)
    for _, i := range edges {
        adj[i[0]] = append(adj[i[0]], [2]int{i[1], i[2]})
        adj[i[1]] = append(adj[i[1]], [2]int{i[0], i[2]})
    }
    cnt := make([]int, n)
    ans := 0

    inf := math.MaxInt
    vis := make([]bool, n)
    dist := make([]int, n)
    pq := &PQ{}
    heap.Init(pq)

    add := func(i, d int) {
        if d < dist[i] {
            dist[i] = d
            heap.Push(pq, Item{i, dist[i]})
        }
    }

    dijkstra := func(start int) {
        for i := 0; i < n; i++ {
            vis[i] = false
            dist[i] = inf
        }
        add(start, 0)
        for pq.Len() > 0 {
            cur := heap.Pop(pq).(Item).node
            if vis[cur] { continue }
            vis[cur] = true
            if dist[cur] > distanceThreshold { continue }
            cnt[start]++
            for _, to := range adj[cur] {
                add(to[0], dist[cur] + to[1])
            }
        }
    }

    for i := 0; i < n; i++ {
        dijkstra(i)
        if cnt[i] < cnt[ans] { ans = i }
        if cnt[i] == cnt[ans] { ans = max(ans, i) }
    }
    return ans
}