const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int inf = INT_MAX;
        int n = edges.size();
        pair<int, int> ans = {inf, -1};
        vector<int> dist(n, inf);
        vector<bool> vis(n, 0);
        for(int i = node1, d = 0; i != -1 && dist[i] == inf; i = edges[i], d++) {
            dist[i] = d;
        }
        for(int i = node2, d = 0; i != -1 && !vis[i]; vis[i] = 1, i = edges[i], d++) {
            ans = min(ans, {max(d, dist[i]), i});
        }
        return ans.second;
    }
};