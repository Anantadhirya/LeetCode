class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const int inf = INT_MAX;
        vector<vector<int>> dist(n, vector<int>(n, inf));
        for(const auto &i: edges) {
            dist[i[0]][i[1]] = min(dist[i[0]][i[1]], i[2]);
            dist[i[1]][i[0]] = min(dist[i[1]][i[0]], i[2]);
        }
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dist[i][k] == inf || dist[k][j] == inf) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int ans, ans2 = inf, tmp;
        for(int i = 0; i < n; i++) {
            tmp = -1;
            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold) {
                    tmp++;
                }
            }
            if(tmp <= ans2) {
                ans2 = tmp;
                ans = i;
            }
        }
        return ans;
    }
};