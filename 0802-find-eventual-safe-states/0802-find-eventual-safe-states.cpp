class Solution {
public:
    void dfs(int curr, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &safe) {
        vis[curr] = 1;
        for(const int &to: adj[curr]) {
            if(!vis[to]) dfs(to, adj, vis, safe);
            if(!safe[to]) {
                safe[curr] = 0;
                return;
            }
        }
        safe[curr] = 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = graph.size();
        vector<bool> vis(n, 0), safe(n, 0);
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, graph, vis, safe);
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};