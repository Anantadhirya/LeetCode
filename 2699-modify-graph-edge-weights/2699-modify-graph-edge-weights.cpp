class Solution {
public:
    int dijkstra(int &n, int &source, int &destination, vector<vector<pair<int, int>>> &adj) {
        const int inf = 2e9;
        priority_queue<pair<int, int>> pq;
        vector<int> dist(n, inf);
        vector<bool> vis(n, 0);
        int curr;
        dist[source] = 0;
        pq.push({-dist[source], source});
        while(!pq.empty()) {
            curr = pq.top().second;
            pq.pop();
            if(vis[curr]) continue;
            vis[curr] = 1;
            for(const auto &[to, w]: adj[curr]) {
                if(dist[curr] + w < dist[to]) {
                    dist[to] = dist[curr] + w;
                    pq.push({-dist[to], to});
                }
            }
        }
        return dist[destination];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        const int inf = 2e9;
        vector<vector<pair<int, int>>> adj(n);
        int m = edges.size();
        int dist;
        for(int i = 0, u, v, w; i < m; i++) {
            u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if(w == -1) continue;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        dist = dijkstra(n, source, destination, adj);
        if(dist < target) return {};
        if(dist > target) {
            for(int i = 0, u, v, w; i < m; i++) {
                if(edges[i][2] != -1) continue;
                u = edges[i][0], v = edges[i][1];
                w = edges[i][2] = 1;
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
                dist = dijkstra(n, source, destination, adj);
                if(dist < target) {
                    edges[i][2] += target - dist;
                    dist = target;
                    break;
                }
            }
        }
        if(dist != target) return {};
        for(int i = 0; i < m; i++) {
            if(edges[i][2] == -1) edges[i][2] = inf;
        }
        return edges;
    }
};