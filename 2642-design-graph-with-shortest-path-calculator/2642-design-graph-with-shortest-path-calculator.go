type Item struct{ node, dist int }
type PQ []Item

func (h PQ) Len() int           { return len(h) }
func (h PQ) Less(i, j int) bool { return h[i].dist < h[j].dist }
func (h PQ) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *PQ) Push(x any)        { *h = append(*h, x.(Item)) }
func (h *PQ) Pop() any          { old := *h; *h = old[:len(old)-1]; return old[len(old)-1] }

type Graph struct {
    n int
    adj [][][2]int
}


func Constructor(n int, edges [][]int) Graph {
    g := Graph{}
    g.n = n
    g.adj = make([][][2]int, n)
    for _, i := range edges {
        g.adj[i[0]] = append(g.adj[i[0]], [2]int{i[1], i[2]})
    }
    return g
}


func (this *Graph) AddEdge(edge []int)  {
    this.adj[edge[0]] = append(this.adj[edge[0]], [2]int{edge[1], edge[2]})
}


func (this *Graph) ShortestPath(node1 int, node2 int) int {
    inf := math.MaxInt
    vis := make([]bool, this.n)
    dist := make([]int, this.n)
    for i := range dist { dist[i] = inf }
    pq := &PQ{}
    heap.Init(pq)

    add := func(i, d int) {
        if d < dist[i] {
            dist[i] = d
            heap.Push(pq, Item{i, dist[i]})
        }
    }

    add(node1, 0)
    for pq.Len() > 0 {
        cur := heap.Pop(pq).(Item).node
        if vis[cur] { continue }
        vis[cur] = true
        for _, to := range this.adj[cur] {
            add(to[0], dist[cur] + to[1])
        }
    }
    if dist[node2] == inf { return -1 }
    return dist[node2]
}


/**
 * Your Graph object will be instantiated and called as such:
 * obj := Constructor(n, edges);
 * obj.AddEdge(edge);
 * param_2 := obj.ShortestPath(node1,node2);
 */