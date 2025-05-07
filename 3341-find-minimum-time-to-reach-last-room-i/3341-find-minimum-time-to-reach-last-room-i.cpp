int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        const int inf = INT_MAX;
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, inf));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int i, j;
        dist[0][0] = 0;
        pq.push({-dist[0][0], {0, 0}});
        while(!pq.empty()) {
            i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            for(int d = 0, ii, jj, dd; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(0 <= ii && ii < n && 0 <= jj & jj < m) {
                    dd = max(dist[i][j], moveTime[ii][jj]) + 1;
                    if(dd < dist[ii][jj]) {
                        dist[ii][jj] = dd;
                        pq.push({-dd, {ii, jj}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};