class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());
        int m = nums.size();
        int ans = 0;
        for(long long i = 1, j = 0; i <= n; ) {
            while(j < m && nums[j] <= i) {
                i += nums[j];
                j++;
            }
            if(i <= n) {
                // cout << i << "\n";
                i += i;
                ans++;
            }
        }
        return ans;
    }
};