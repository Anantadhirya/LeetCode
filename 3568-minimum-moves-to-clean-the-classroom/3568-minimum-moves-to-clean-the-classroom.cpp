int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int minMoves(vector<string>& c, int energy) {
        const int inf = INT_MAX;
        int n = c.size(), m = c[0].size();
        int l = 0, sx, sy;
        int curi, curj, curmask, cure, curd;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(c[i][j] == 'L') c[i][j] = l++;
                if(c[i][j] == 'S') sx = i, sy = j;
            }
        }
        vector<vector<vector<bool>>> vis(n*m, vector<vector<bool>>(1<<l, vector<bool>(energy+1, 0)));
        vector<vector<int>> be(n*m, vector<int>(1<<l, -1));
        queue<array<int, 5>> q;
        auto add = [&](int i, int j, int mask, int e, int d) -> void {
            if(e <= be[i*m+j][mask]) return;
            be[i*m+j][mask] = e;
            if(vis[i*m+j][mask][e]) return;
            vis[i*m+j][mask][e] = 1;
            q.push({i, j, mask, e, d});
        };
        add(sx, sy, 0, energy, 0);
        while(!q.empty()) {
            curi = q.front()[0], curj = q.front()[1], curmask = q.front()[2], cure = q.front()[3], curd = q.front()[4];
            q.pop();
            if(curmask == (1<<l)-1) return curd;
            if(cure == 0) continue;
            for(int d = 0, ii, jj, new_mask, ee; d < 4; d++) {
                ii = curi + dx[d];
                jj = curj + dy[d];
                new_mask = curmask;
                ee = cure - 1;
                if(ii < 0 || ii >= n || jj < 0 || jj >= m || c[ii][jj] == 'X') continue;
                if(c[ii][jj] == 'R') ee = energy;
                if(c[ii][jj] < 10) new_mask |= (1<<c[ii][jj]);
                add(ii, jj, new_mask, ee, curd + 1);
            }
        }
        return -1;
    }
};