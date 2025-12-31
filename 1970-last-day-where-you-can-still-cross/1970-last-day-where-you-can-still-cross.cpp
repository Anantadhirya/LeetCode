int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    bool check(int x, int row, int col, vector<vector<int>> &v) {
        vector<vector<bool>> vis(row, vector<bool>(col, 0));
        queue<pair<int, int>> q;
        for(int j = 0; j < col; j++) q.push({0, j});
        for(int i, j; !q.empty(); ) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            if(v[i][j] <= x) continue;
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            if(i == row-1) return 1;
            for(int ii, jj, d = 0; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(ii < 0 || ii >= row || jj < 0 || jj >= col) continue;
                q.push({ii, jj});
            }
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> v(row, vector<int>(col));
        int ans = 0;
        for(int i = 0; i < row*col; i++) {
            v[cells[i][0]-1][cells[i][1]-1] = i+1;
        }
        for(int l = 0, r = row*col, mid; l <= r; ) {
            mid = (l+r)/2;
            if(check(mid, row, col, v)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};