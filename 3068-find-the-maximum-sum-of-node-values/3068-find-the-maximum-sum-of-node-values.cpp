class Solution {
public:
    void dfs(int curr, int from, long long &k, vector<int> &nums, vector<vector<int>> &adj, vector<vector<long long>> &dp) {
        vector<long long> tmp;
        dp[curr][0] = 0;
        long long flip, noflip;
        for(const auto &to: adj[curr]) {
            if(to == from) continue;
            dfs(to, curr, k, nums, adj, dp);
            tmp = dp[curr];
            noflip = dp[to][0] + nums[to];
            flip = dp[to][0] + (k^nums[to]);
            if(dp[to][1] != -1) {
                noflip = max(noflip, dp[to][1] + (k^nums[to]));
                flip = max(flip, dp[to][1] + nums[to]);
            }
            dp[curr][0] = tmp[0] + noflip;
            dp[curr][1] = tmp[0] + flip;
            if(tmp[1] != -1) {
                dp[curr][0] = max(dp[curr][0], tmp[1] + flip);
                dp[curr][1] = max(dp[curr][1], tmp[1] + noflip);
            }
        }
    }
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        long long x = k;
        vector<vector<int>> adj(n);
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        for(const auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0, -1, x, nums, adj, dp);
        return max(dp[0][0] + nums[0], dp[0][1] + ((long long)k^nums[0]));
    }
};