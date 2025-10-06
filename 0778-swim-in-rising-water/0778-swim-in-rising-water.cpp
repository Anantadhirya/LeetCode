int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, INT_MAX));
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        priority_queue<pair<int, pair<int, int>>> pq;
        ans[0][0] = grid[0][0];
        pq.push({-ans[0][0], {0, 0}});
        int i, j;
        while(!pq.empty()) {
            i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            for(int d = 0, ii, jj, dd; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(0 <= ii && ii < n && 0 <= jj && jj < n && max(ans[i][j], grid[ii][jj]) < ans[ii][jj]) {
                    ans[ii][jj] = max(ans[i][j], grid[ii][jj]);
                    pq.push({-ans[ii][jj], {ii, jj}});
                }
            }
        }
        return ans[n-1][n-1];
    }
};