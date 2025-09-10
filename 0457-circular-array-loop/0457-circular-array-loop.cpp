class Solution {
public:
    void dfs(int curr, int &start, int &n, vector<bool> &vis, vector<bool> &done, vector<int> &nums, bool &ans) {
        if(done[curr] || ans) return;
        if(nums[curr] * nums[start] < 0) return;
        if(vis[curr]) {
            ans = 1;
            return;
        }
        vis[curr] = 1;
        if(abs(nums[curr]) % n != 0) dfs(((curr + nums[curr]) % n + n) % n, start, n, vis, done, nums, ans);
        done[curr] = 1;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, 0), done(n, 0);
        bool ans = 0;
        for(int i = 0; i < n && !ans; i++) {
            dfs(i, i, n, vis, done, nums, ans);
        }
        return ans;
    }
};