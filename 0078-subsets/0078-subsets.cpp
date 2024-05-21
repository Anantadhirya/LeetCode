class Solution {
public:
    void solve(int i, int &n, vector<int> &nums, vector<int> &tmp, vector<vector<int>> &ans) {
        if(i == n) {
            ans.push_back(tmp);
            return;
        }
        solve(i+1, n, nums, tmp, ans);
        tmp.push_back(nums[i]);
        solve(i+1, n, nums, tmp, ans);
        tmp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        vector<int> tmp;
        vector<vector<int>> ans;
        solve(0, n, nums, tmp, ans);
        return ans;
    }
};