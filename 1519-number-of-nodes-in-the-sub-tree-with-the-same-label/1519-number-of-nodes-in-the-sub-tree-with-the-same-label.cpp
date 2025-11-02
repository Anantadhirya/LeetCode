class Solution {
public:
    void dfs(int cur, int from, vector<vector<int>> &adj, vector<vector<int>> &cnt, vector<int> &ans, string &labels) {
        for(auto to: adj[cur]) {
            if(to == from) continue;
            dfs(to, cur, adj, cnt, ans, labels);
            for(int i = 0; i < 26; i++) {
                cnt[cur][i] += cnt[to][i];
            }
        }
        ans[cur] = ++cnt[cur][labels[cur]-'a'];
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n), cnt(n, vector<int>(26, 0));
        vector<int> ans(n, 0);
        for(auto i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0, -1, adj, cnt, ans, labels);
        return ans;
    }
};