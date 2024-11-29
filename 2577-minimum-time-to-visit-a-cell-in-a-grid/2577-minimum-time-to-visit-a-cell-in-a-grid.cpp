class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    const int inf = INT_MAX;
    int minimumTime(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, inf));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        priority_queue<vector<int>> pq;
        dist[0][0] = 0;
        pq.push({-dist[0][0], 0, 0});
        for(int i, j, ii, jj, d, tmp, adj; !pq.empty(); ) {
            i = pq.top()[1];
            j = pq.top()[2];
            pq.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            adj = 0;
            for(d = 0; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                if(grid[ii][jj] <= dist[i][j] + 1) {
                    adj = 1;
                    break;
                }
            }
            for(d = 0; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                tmp = dist[i][j] + 1;
                if(dist[i][j] + 1 < grid[ii][jj]) {
                    if(!adj) continue;
                    tmp = grid[ii][jj] + (dist[i][j] % 2 == grid[ii][jj] % 2);
                }
                if(tmp < dist[ii][jj]) {
                    dist[ii][jj] = tmp;
                    pq.push({-tmp, ii, jj});
                }
            }
        }
        return dist[n-1][m-1] == inf ? -1 : dist[n-1][m-1];
    }
};