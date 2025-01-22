int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isWater[i][j] == 1) {
                    isWater[i][j] = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        for(int i, j; !q.empty(); ) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for(int ii, jj, d = 0; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(0 <= ii && ii < n && 0 <= jj && jj < m && !vis[ii][jj]) {
                    isWater[ii][jj] = isWater[i][j] + 1;
                    q.push({ii, jj});
                    vis[ii][jj] = 1;
                }
            }
        }
        return isWater;
    }
};