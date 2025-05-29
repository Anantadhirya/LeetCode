class Solution {
public:
    void dfs(int curr, int from, int p, vector<vector<int>> &adj, vector<int> &par, vector<int> &cnt) {
        par[curr] = p;
        cnt[p]++;
        for(const int &to: adj[curr]) {
            if(to == from) continue;
            dfs(to, curr, 1-p, adj, par, cnt);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        vector<int> par1(n), par2(m), cnt1(2, 0), cnt2(2, 0);
        vector<int> ans(n);
        for(const auto &i: edges1) {
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(const auto &i: edges2) {
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }
        dfs(0, -1, 0, adj1, par1, cnt1);
        dfs(0, -1, 0, adj2, par2, cnt2);
        m = max(cnt2[0], cnt2[1]);
        for(int i = 0; i < n; i++) {
            ans[i] = cnt1[par1[i]] + m;
        }
        return ans;
    }
};