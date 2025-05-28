class Solution {
public:
    int dfs(int curr, int from, int k, vector<vector<int>> &adj) {
        if(k < 0) return -1;
        if(k == 0) return 1;
        int ret = 1;
        for(const int &to: adj[curr]) {
            if(to == from) continue;
            ret += dfs(to, curr, k-1, adj);
        }
        return ret;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        vector<int> ans(n);
        int mx = 0;
        for(const auto &i: edges1) {
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(const auto &i: edges2) {
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < m; i++) {
            mx = max(mx, dfs(i, -1, k-1, adj2));
        }
        for(int i = 0; i < n; i++) {
            ans[i] = dfs(i, -1, k, adj1) + mx;
        }
        return ans;
    }
};