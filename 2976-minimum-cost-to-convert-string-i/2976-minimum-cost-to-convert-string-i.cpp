class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const int inf = INT_MAX;
        vector<vector<int>> dist(26, vector<int>(26, inf));
        int n = source.size(), m = original.size();
        for(int i = 0, u, v, w; i < m; i++) {
            u = original[i] - 'a', v = changed[i] - 'a', w = cost[i];
            dist[u][v] = min(dist[u][v], w);
        }
        for(int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    if(dist[i][k] == inf || dist[k][j] == inf) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0, u, v; i < n; i++) {
            u = source[i] - 'a', v = target[i] - 'a';
            if(dist[u][v] == inf) return -1;
            ans += (long long)dist[u][v];
        }
        return ans;
    }
};