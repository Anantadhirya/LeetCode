class Solution {
public:
    void dfs(int curr, vector<vector<int>> &adj, vector<bool> &valid, vector<bool> &vis) {
        vis[curr] = 1;
        bool tmp = 1;
        if(adj[curr].size() == 0) tmp = 0;
        for(const int &to: adj[curr]) {
            if(!vis[to]) dfs(to, adj, valid, vis);
            if(!valid[to]) {
                tmp = 0;
                return;
            }
        }
        valid[curr] = tmp;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = 0, k = recipes.size(), idx;
        unordered_map<string, int> m;
        vector<string> ans;
        for(const string &i: recipes) {
            m[i] = 0;
        }
        for(const auto &i: ingredients) {
            for(const string &j: i) {
                m[j] = 0;
            }
        }
        for(const string &i: supplies) {
            m[i] = 0;
        }
        for(auto &[_, v]: m) {
            v = n++;
        }
        vector<vector<int>> adj(n);
        vector<bool> vis(n, 0), valid(n, 0);
        for(int i = 0; i < k; i++) {
            idx = m[recipes[i]];
            for(const auto &s: ingredients[i]) {
                adj[idx].push_back(m[s]);
            }
        }
        for(const auto &i: supplies) {
            idx = m[i];
            vis[idx] = valid[idx] = 1;
        }
        for(const auto &i: recipes) {
            idx = m[i];
            if(!vis[idx]) dfs(idx, adj, valid, vis);
            if(valid[idx]) ans.push_back(i);
        }
        return ans;
    }
};