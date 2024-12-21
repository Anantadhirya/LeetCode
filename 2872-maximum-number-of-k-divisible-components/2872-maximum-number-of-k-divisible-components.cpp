class Solution {
public:
    long long dfs(int curr, int from, vector<vector<int>> &adj, vector<int> &values, int &k, int &ans) {
        long long sm = values[curr];
        for(const int &to: adj[curr]) {
            if(to == from) continue;
            sm += dfs(to, curr, adj, values, k, ans);
        }
        ans += (sm % k == 0);
        return sm;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        int ans = 0;
        for(const auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0, -1, adj, values, k, ans);
        return ans;
    }
};