class Solution {
public:
    void dfs(int curr, int from, vector<vector<int>> &adj, vector<long long> &v, int &k, int &ans) {
        for(const int &to: adj[curr]) {
            if(to == from) continue;
            dfs(to, curr, adj, v, k, ans);
            v[curr] += v[to];
        }
        ans += (v[curr] % k == 0);
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        vector<long long> v(values.begin(), values.end());
        int ans = 0;
        for(const auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0, -1, adj, v, k, ans);
        return ans;
    }
};