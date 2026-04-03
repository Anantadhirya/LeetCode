class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size(), m = walls.size();
        vector<pair<int, int>> v(n);
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        for(int i = 0; i < n; i++) {
            v[i] = {robots[i], distance[i]};
        }
        sort(v.begin(), v.end());
        sort(walls.begin(), walls.end());
        auto cnt = [&](int l, int r) -> int {
            // [l, r] inclusive
            if(r < l) return 0;
            return upper_bound(walls.begin(), walls.end(), r) - lower_bound(walls.begin(), walls.end(), l);
        };
        for(int i = 1, l, r, prefr = 0; i <= n; i++) {
            // left
            r = v[i-1].first;
            l = v[i-1].first - v[i-1].second;
            if(i-1 >= 1) l = max(l, v[i-2].first+1);
            dp[i][0] = max(dp[i-1][0] + cnt(l, r), dp[i-1][1] + cnt(max(l, prefr+1), r));
            
            // right
            l = v[i-1].first;
            r = v[i-1].first + v[i-1].second;
            if(i+1 <= n) r = min(r, v[i].first-1);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + cnt(l, r);
            prefr = r;
        }
        return max(dp[n][0], dp[n][1]);
    }
};