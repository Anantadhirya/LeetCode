int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int inf = INT_MAX;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, inf));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        priority_queue<pair<int, pair<int, int>>> pq;
        dist[0][0] = 0;
        pq.push({-0, {0, 0}});
        for(int i, j; !pq.empty(); ) {
            i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            for(int d = 0, ii, jj, dd; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                dd = dist[i][j] + (d+1 != grid[i][j]);
                if(0 <= ii && ii < n && 0 <= jj && jj < m && dd < dist[ii][jj]) {
                    dist[ii][jj] = dd;
                    pq.push({-dist[ii][jj], {ii, jj}});
                }
            }
        }
        return dist[n-1][m-1];
    }
};