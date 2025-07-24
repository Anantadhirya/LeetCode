class Solution {
public:
    void dfs(int curr, int from, vector<int> &nums, vector<vector<int>> &adj, int &t, vector<int> &tin, vector<int> &tout) {
        tin[curr] = t++;
        for(const int &to: adj[curr]) {
            if(to == from) continue;
            dfs(to, curr, nums, adj, t, tin, tout);
            nums[curr] ^= nums[to];
        }
        tout[curr] = t;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), t = 0;
        vector<int> tin(n), tout(n);
        vector<vector<int>> adj(n);
        for(const auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans = INT_MAX;
        dfs(0, -1, nums, adj, t, tin, tout);
        for(int i = 1, a, b, c; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                a = nums[0] ^ nums[i] ^ nums[j];
                b = nums[i];
                c = nums[j];
                if(tin[i] <= tin[j] && tout[j] <= tout[i]) {
                    a ^= nums[j];
                    b ^= nums[j];
                }
                if(tin[j] <= tin[i] && tout[i] <= tout[j]) {
                    a ^= nums[i];
                    c ^= nums[i];
                }
                ans = min(ans, max(a, max(b, c)) - min(a, min(b, c)));
            }
        }
        return ans;
    }
};