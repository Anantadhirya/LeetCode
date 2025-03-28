const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<int> v(n*m);
        dist[0][0] = grid[0][0];
        pq.push({-dist[0][0], {0, 0}});
        for(int i, j; !pq.empty(); ) {
            i = pq.top().second.first;
            j = pq.top().second.second;
            pq.pop();
            for(int d = 0, ii, jj, dd; d < 4; d++) {
                ii = i + dx[d];
                jj = j + dy[d];
                if(0 <= ii && ii < n && 0 <= jj && jj < m) {
                    dd = max(dist[i][j], grid[ii][jj]);
                    if(dd < dist[ii][jj]) {
                        dist[ii][jj] = dd;
                        pq.push({-dist[ii][jj], {ii, jj}});
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v[m*i+j] = dist[i][j];
            }
        }
        sort(v.begin(), v.end());
        for(auto &i: queries) {
            i = lower_bound(v.begin(), v.end(), i) - v.begin();
        }
        return queries;
    }
};