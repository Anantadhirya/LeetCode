class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0, j = 0; i < n; i++) {
            while(nums[i] - nums[j] > 2*k) j++;
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};