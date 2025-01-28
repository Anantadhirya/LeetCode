int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int ans = 0, curr;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    q.push({i, j});
                    curr = grid[i][j];
                    grid[i][j] = 0;
                    for(int ii, jj; !q.empty(); ) {
                        ii = q.front().first;
                        jj = q.front().second;
                        q.pop();
                        for(int ito, jto, d = 0; d < 4; d++) {
                            ito = ii + dx[d];
                            jto = jj + dy[d];
                            if(0 <= ito && ito < n && 0 <= jto && jto < m && grid[ito][jto]) {
                                q.push({ito, jto});
                                curr += grid[ito][jto];
                                grid[ito][jto] = 0;
                            }
                        }
                    }
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};