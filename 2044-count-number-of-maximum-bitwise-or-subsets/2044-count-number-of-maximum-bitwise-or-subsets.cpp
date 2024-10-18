class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size();
        int mx = 0, ans = 0, tmp;
        for(const int &i: nums) {
            mx |= i;
        }
        for(int mask = 0; mask < (1<<n); mask++) {
            tmp = 0;
            for(int i = 0; i < n; i++) {
                if((mask>>i)&1) tmp |= nums[i];
            }
            ans += (tmp == mx);
        }
        return ans;
    }
};