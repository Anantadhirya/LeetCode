class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        if(source == target) return 0;
        int max_stop = -1;
        for(const auto &route: routes) {
            for(const int &stop: route) {
                max_stop = max(max_stop, stop);
            }
        }
        if(max_stop < source || max_stop < target) return -1;
        vector<vector<int>> in_routes(max_stop+1);
        vector<bool> vis(max_stop+1, 0);
        int n = routes.size();
        vector<int> dist(n, -1);
        queue<int> q;
        int curr;
        for(int i = 0; i < n; i++) {
            for(const int &j: routes[i]) {
                in_routes[j].push_back(i);
            }
        }
        for(const int &i: in_routes[source]) {
            dist[i] = 1;
            q.push(i);
        }
        vis[source] = 1;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(const int &i: routes[curr]) {
                if(i == target) return dist[curr];
                if(vis[i]) continue;
                for(const int &j: in_routes[i]) {
                    if(dist[j] != -1) continue;
                    dist[j] = dist[curr] + 1;
                    q.push(j);
                }
                vis[i] = 1;
            }
        }
        return -1;
    }
};