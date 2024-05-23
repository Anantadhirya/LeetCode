class Solution {
public:
    void solve(int curr, int &n, int &k, vector<int> &m, vector<int> &nums, int &ans) {
        if(curr == n) {
            ans++;
            return;
        }
        solve(curr+1, n, k, m, nums, ans);
        if(nums[curr] - k < 1 || m[nums[curr] - k] == 0) {
            m[nums[curr]]++;
            solve(curr+1, n, k, m, nums, ans);
            m[nums[curr]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size(), ans = 0;
        vector<int> m(1000+5, 0);
        sort(nums.begin(), nums.end());
        solve(0, n, k, m, nums, ans);
        return ans - 1;
    }
};