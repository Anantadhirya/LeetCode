class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        const int inf = INT_MAX;
        vector<int> dist(2*n, inf), vis(2*n, 0);
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> adj(n);
        int curr, new_dist;
        
        for(const auto &i: edges) {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        dist[0] = 0;
        pq.push({-dist[0], 0});
        while(!pq.empty()) {
            curr = pq.top().second;
            pq.pop();
            if(vis[curr/2] > curr % 2) continue;
            new_dist = dist[curr] + time;
            if(dist[curr] % (2*change) >= change) {
                new_dist += 2*change - dist[curr] % (2*change);
            }
            for(const auto &to: adj[curr/2]) {
                if(new_dist < dist[2*to]) {
                    dist[2*to+1] = dist[2*to];
                    dist[2*to] = new_dist;
                    pq.push({-dist[2*to], 2*to});
                    pq.push({-dist[2*to+1], 2*to+1});
                } else if(new_dist < dist[2*to+1] && new_dist != dist[2*to]) {
                    dist[2*to+1] = new_dist;
                    pq.push({-dist[2*to+1], 2*to+1});
                }
            }
        }
        // for(int i = 0; i < n; i++) {
        //     cout << i+1 << " " << dist[2*i] << " " << dist[2*i+1] << "\n";
        // }
        return dist[2*n-1];
    }
};