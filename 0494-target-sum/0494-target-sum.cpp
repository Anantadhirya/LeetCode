class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int sm = 0;
        for(const auto &i: nums) {
            sm += i;
        }
        vector<int> ans(2*sm+1, 0), ans2(2*sm+1, 0);
        ans[sm] = 1;
        for(auto &i: nums) {
            swap(ans, ans2);
            for(int j = 0; j <= 2*sm; j++) {
                ans[j] = 0;
                if(j - i >= 0) ans[j] += ans2[j-i];
                if(j + i <= 2*sm) ans[j] += ans2[j+i];
            }
        }
        return -sm <= target && target <= sm ? ans[target+sm] : 0;
    }
};