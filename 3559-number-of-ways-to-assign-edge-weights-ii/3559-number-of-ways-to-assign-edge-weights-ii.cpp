class Graf {
public:
    int n, lg, t = -1;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, d;
    Graf(vector<vector<int>> &edges) {
        n = edges.size()+1;
        lg = log2(n) + 3;
        adj.resize(n);
        tin.resize(n);
        tout.resize(n);
        d.resize(n);
        up.assign(n, vector<int>(lg));
        for(auto &i: edges) {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        dfs(0, 0);
    }
    void dfs(int cur, int from, int depth = 0) {
        tin[cur] = ++t;
        d[cur] = depth;
        up[cur][0] = from;
        for(int i = 1; i < lg; i++) {
            up[cur][i] = up[up[cur][i-1]][i-1];
        }
        for(int &to: adj[cur]) {
            if(to == from) continue;
            dfs(to, cur, depth+1);
        }
        tout[cur] = t;
    }
    bool isanc(int a, int b) {
        return tin[a] <= tin[b] && tout[b] <= tout[a];
    }
    int lca(int u, int v) {
        if(isanc(u, v)) return u;
        if(isanc(v, u)) return v;
        for(int i = lg-1; i >= 0; i--) {
            if(!isanc(up[u][i], v)) u = up[u][i];
        }
        return up[u][0];
    }
};

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = edges.size()+1;
        Graf g(edges);
        int l, d;
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        vector<int> ans;
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        }
        for(auto &i: queries) {
            i[0]--, i[1]--;
            l = g.lca(i[0], i[1]);
            d = g.d[i[0]] + g.d[i[1]] - 2*g.d[l];
            ans.push_back(dp[d][1]);
        }
        return ans;
    }
};