const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = grid.size();
        queue<pair<int, int>> q;
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        vector<vector<int>> v(n, vector<int>(n, INT_MAX)), ans(n, vector<int>(n, 0));
        pair<int, int> curr;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    q.push({i, j});
                    v[i][j] = 0;
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()) {
            curr = q.front();
            q.pop();
            for(int d = 0, i, j; d < 4; d++) {
                i = curr.first + dx[d];
                j = curr.second + dy[d];
                if(0 <= i && i < n && 0 <= j && j < n && !vis[i][j]) {
                    q.push({i, j});
                    v[i][j] = v[curr.first][curr.second] + 1;
                    vis[i][j] = 1;
                }
            }
        }
        vis.assign(n, vector<bool>(n, 0));
        ans[0][0] = v[0][0];
        pq.push({ans[0][0], {0, 0}});
        while(!pq.empty()) {
            curr = pq.top().second;
            pq.pop();
            if(vis[curr.first][curr.second]) continue;
            vis[curr.first][curr.second] = 0;
            for(int d = 0, i, j, tmp; d < 4; d++) {
                i = curr.first + dx[d];
                j = curr.second + dy[d];
                if(0 <= i && i < n && 0 <= j && j < n) {
                    tmp = min(v[i][j], ans[curr.first][curr.second]);
                    if(tmp > ans[i][j]) {
                        ans[i][j] = tmp;
                        pq.push({ans[i][j], {i, j}});
                    }
                }
            }
        }
        return ans[n-1][n-1];
    }
};