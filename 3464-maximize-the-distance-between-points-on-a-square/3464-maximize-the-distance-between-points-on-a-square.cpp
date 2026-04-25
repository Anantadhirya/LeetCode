class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> v;
        long long ans = -1;
        for(auto p: points) {
            // (0, 0) -> (0, side)
            // (0, side) -> (side, side)
            // (side, side) -> (side, 0)
            // (side, 0) -> (0, 0)
            if(p[0] == 0 || p[1] == side) v.push_back((long long)p[0] + p[1]);
            else v.push_back((long long)2*side + (side - p[0]) + (side - p[1]));
        }
        sort(v.begin(), v.end());
        vector<pair<int, long long>> dp(n);
        auto check = [&](int x) -> bool {
            for(int i = n-1, j = n-1; i >= 0; i--) {
                dp[i] = {1, v[i]};
                while(j > i && v[j] - v[i] >= x) j--;
                if(i < j+1 && j+1 < n) dp[i] = {1 + dp[j+1].first, dp[j+1].second};
                if(dp[i].first - (v[i] + 4ll*side - dp[i].second < x) >= k) return 1;
            }
            return 0;
        };
        for(long long l = 0, r = 4ll*side, mid; l <= r; ) {
            mid = (l+r)/2;
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};