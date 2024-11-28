class Solution {
public:
    const int inf = INT_MAX;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, inf));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        priority_queue<vector<int>> pq;
        dist[0][0] = 0;
        pq.push({-dist[0][0], 0, 0});
        for(int i, j, ii, jj, tmp, d; !pq.empty(); ) {
            i = pq.top()[1];
            j = pq.top()[2];
            pq.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            for(d = 0; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                tmp = dist[i][j] + grid[ii][jj];
                if(tmp < dist[ii][jj]) {
                    dist[ii][jj] = tmp;
                    pq.push({-dist[ii][jj], ii, jj});
                }
            }
        }
        return dist[n-1][m-1];
    }
};