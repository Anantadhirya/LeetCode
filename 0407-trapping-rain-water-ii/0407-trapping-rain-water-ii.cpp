int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heights) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        priority_queue<pair<int, pair<int, int>>> pq;
        int n = heights.size(), m = heights[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for(int i = 0; i < n; i++) {
            pq.push({-heights[i][0], {i, 0}});
            pq.push({-heights[i][m-1], {i, m-1}});
            vis[i][0] = 1;
            vis[i][m-1] = 1;
        }
        for(int j = 1; j < m-1; j++) {
            pq.push({-heights[0][j], {0, j}});
            pq.push({-heights[n-1][j], {n-1, j}});
            vis[0][j] = 1;
            vis[n-1][j] = 1;
        }
        for(int i, j; !pq.empty(); ) {
            i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();
            for(int d = 0, ii, jj, dd; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(0 <= ii && ii < n && 0 <= jj && jj < m && !vis[ii][jj]) {
                    if(heights[i][j] > heights[ii][jj]) {
                        ans += heights[i][j] - heights[ii][jj];
                        heights[ii][jj] = heights[i][j];
                    }
                    pq.push({-heights[ii][jj], {ii, jj}});
                    vis[ii][jj] = 1;
                }
            }
        }
        return ans;
    }
};