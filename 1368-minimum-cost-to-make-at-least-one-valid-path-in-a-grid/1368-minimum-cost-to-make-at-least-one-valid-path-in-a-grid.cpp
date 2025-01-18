int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        deque<pair<int, int>> dq;
        dist[0][0] = 0;
        dq.push_front({0, 0});
        for(int i, j; !dq.empty(); ) {
            i = dq.front().first;
            j = dq.front().second;
            dq.pop_front();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            for(int d = 0, ii, jj, dd; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                dd = dist[i][j] + (d+1 != grid[i][j]);
                if(0 <= ii && ii < n && 0 <= jj && jj < m && dd < dist[ii][jj]) {
                    dist[ii][jj] = dd;
                    if(dist[ii][jj] == dist[i][j]) dq.push_front({ii, jj});
                    else dq.push_back({ii, jj});
                }
            }
        }
        return dist[n-1][m-1];
    }
};