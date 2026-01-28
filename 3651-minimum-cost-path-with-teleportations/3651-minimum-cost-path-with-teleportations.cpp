class Solution {
public:
    void ms(int &a, int b) {
        a = min(a, b);
    }
    int minCost(vector<vector<int>>& grid, int k) {
        const int inf = INT_MAX;
        int n = grid.size(), m = grid[0].size();
        int mn;
        vector<pair<int, pair<int, int>>> points;
        vector<vector<int>> dist(n, vector<int>(m, inf));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                points.push_back({grid[i][j], {i, j}});
            }
        }
        sort(points.begin(), points.end());
        for(int l = 0; l <= k; l++) {
            mn = inf;
            for(int i = n*m-1, j = n*m-1; i >= 0; i = j) {
                while(j >= 0 && points[j].first == points[i].first) {
                    ms(mn, dist[points[j].second.first][points[j].second.second]);
                    j--;
                }
                for(int k = j+1; k <= i; k++) {
                    ms(dist[points[k].second.first][points[k].second.second], mn);
                }
            }
            dist[0][0] = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(i-1 >= 0) ms(dist[i][j], dist[i-1][j] + grid[i][j]);
                    if(j-1 >= 0) ms(dist[i][j], dist[i][j-1] + grid[i][j]);
                }
            }
        }
        return dist[n-1][m-1];
    }
};