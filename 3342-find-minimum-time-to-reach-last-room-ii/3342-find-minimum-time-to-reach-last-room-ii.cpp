int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        const int inf = INT_MAX;
        int n = moveTime.size(), m = moveTime[0].size();
        int i, j, k;
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, {inf, inf}));
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, {0, 0}));
        priority_queue<array<int, 4>> pq;
        dist[0][0][0] = 0;
        pq.push({-0, 0, 0, 0});
        while(!pq.empty()) {
            i = pq.top()[1];
            j = pq.top()[2];
            k = pq.top()[3];
            pq.pop();
            if(vis[i][j][k]) continue;
            vis[i][j][k] = 1;
            for(int d = 0, ii, jj, kk, dd; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(0 <= ii && ii < n && 0 <= jj && jj < m) {
                    kk = 1 - k;
                    dd = max(dist[i][j][k], moveTime[ii][jj]) + 1 + k;
                    if(dd < dist[ii][jj][kk]) {
                        dist[ii][jj][kk] = dd;
                        pq.push({-dd, ii, jj, kk});
                    }
                }
            }
        }
        return min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    }
};