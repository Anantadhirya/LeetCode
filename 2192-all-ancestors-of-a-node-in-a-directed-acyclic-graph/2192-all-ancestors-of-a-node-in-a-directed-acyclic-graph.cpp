class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<vector<int>> ans(n), adj(n);
        vector<int> vis(n, -1);
        stack<int> s;
        int curr;
        for(const auto &i: edges) {
            adj[i[0]].push_back(i[1]);
        }
        for(int i = 0; i < n; i++) {
            s.push(i);
            while(!s.empty()) {
                curr = s.top();
                s.pop();
                if(vis[curr] == i) continue;
                vis[curr] = i;
                if(curr != i) ans[curr].push_back(i);
                for(const int &to: adj[curr]) {
                    s.push(to);
                }
            }
        }
        return ans;
    }
};