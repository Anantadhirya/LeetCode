class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<vector<bool>> mat(n, vector<bool>(n, 0));
        for(const auto &i: prerequisites) {
            adj[i[0]].push_back(i[1]);
        }
        for(int i = 0, curr; i < n; i++) {
            vis.assign(n, 0);
            q.push(i);
            vis[i] = 1;
            while(!q.empty()) {
                curr = q.front();
                q.pop();
                for(const int &to: adj[curr]) {
                    if(vis[to]) continue;
                    q.push(to);
                    mat[i][to] = 1;
                    vis[to] = 1;
                }
            }
        }
        vector<bool> ans;
        for(const auto &i: queries) {
            ans.push_back(mat[i[0]][i[1]]);
        }
        return ans;
    }
};