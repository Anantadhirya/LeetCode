int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size(), m = grid[0].size();
        const int inf = INT_MAX;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, inf));
        priority_queue<pair<int, pair<int, int>>> pq;

        auto add = [&](int i, int j, int d) -> void {
            if(d < dist[i][j]) {
                dist[i][j] = d;
                pq.push({-d, {i, j}});
            }
        };
        add(0, 0, grid[0][0]);
        for(int i, j; !pq.empty(); ) {
            i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            for(int d = 0, ii, jj; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(0 <= ii && ii < n && 0 <= jj && jj < m) {
                    add(ii, jj, dist[i][j] + grid[ii][jj]);
                }
            }
        }
        return dist[n-1][m-1] < health;
    }
};