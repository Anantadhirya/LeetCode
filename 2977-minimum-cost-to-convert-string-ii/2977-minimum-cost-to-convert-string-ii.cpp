class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        map<string, int> m;
        const long long inf = LLONG_MAX;
        int n = source.size(), k = original.size(), t = 0;
        vector<vector<long long>> dist;

        for(auto i: original) m[i] = 0;
        for(auto i: changed) m[i] = 0;
        for(auto [i, _]: m) m[i] = t++;

        dist.assign(t, vector<long long>(t, inf));
        for(int i = 0; i < t; i++) {
            dist[i][i] = 0;
        }
        for(int e = 0, u, v, w; e < k; e++) {
            u = m[original[e]];
            v = m[changed[e]];
            w = cost[e];
            for(int i = 0; i < t; i++) {
                for(int j = 0; j < t; j++) {
                    if(dist[i][u] == inf || dist[v][j] == inf) continue;
                    dist[i][j] = min(dist[i][j], dist[i][u] + w + dist[v][j]);
                }
            }
        }

        long long KEY = 461;
        long long MOD = 1e9 + 7;
        map<long long, int> m2;
        long long tmp, tmpt;
        for(auto [s, v]: m) {
            tmp = 0;
            for(auto i: s) {
                tmp = (tmp * KEY % MOD + i) % MOD;
            }
            m2[tmp] = v;
        }
        vector<long long> dp(n+1, inf);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == inf) continue;
            if(source[i] == target[i]) dp[i+1] = min(dp[i+1], dp[i]);
            tmp = tmpt = 0;
            for(int j = i+1, a, b; j <= n; j++) {
                tmp = (tmp * KEY % MOD + source[j-1]) % MOD;
                tmpt = (tmpt * KEY % MOD + target[j-1]) % MOD;
                if(!m2.count(tmp) || !m2.count(tmpt)) continue;
                a = m2[tmp];
                b = m2[tmpt];
                if(dist[a][b] == inf) continue;
                dp[j] = min(dp[j], dp[i] + dist[a][b]);
            }
        }

        return dp[n] == inf ? -1 : dp[n];
    }
};