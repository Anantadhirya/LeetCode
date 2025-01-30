class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, 0);
        vector<int> cc, group(n, -1);
        int ans = 0, tmp;
        queue<int> q;
        for(const auto &i: edges) {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            cc.clear();
            vis[i] = 1;
            q.push(i);
            for(int curr; !q.empty(); ) {
                curr = q.front();
                cc.push_back(curr);
                q.pop();
                for(const int &to: adj[curr]) {
                    if(!vis[to]) {
                        vis[to] = 1;
                        q.push(to);
                    }
                }
            }
            tmp = 0;
            for(const int &start: cc) {
                for(const int &j: cc) {
                    group[j] = -1;
                }
                q.push(start);
                group[start] = 1;
                for(int curr; !q.empty(); ) {
                    curr = q.front();
                    tmp = max(tmp, group[curr]);
                    q.pop();
                    for(const int &to: adj[curr]) {
                        if(group[to] == -1) {
                            q.push(to);
                            group[to] = group[curr] + 1;
                        } else {
                            if(abs(group[to]-group[curr]) != 1) return -1;
                        }
                    }
                }
            }
            ans += tmp;
        }
        return ans;
    }
};