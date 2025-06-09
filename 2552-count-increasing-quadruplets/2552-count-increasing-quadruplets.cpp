class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<vector<int>> pref(n+1, vector<int>(n+1, 0));
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1];
            for(int j = nums[i-1]; j <= n; j++) {
                pref[i][j]++;
            }
        }
        for(int j = 1; j <= n; j++) {
            for(int k = j+1; k <= n; k++) {
                if(nums[k-1] >= nums[j-1]) continue;
                // banyaknya kiri < nums[k] * banyaknya kanan > nums[j]
                // banyaknya kanan > nums[j] = (banyaknya > nums[j]) - (banyaknya kiri > nums[j])
                //                           = (banyaknya > nums[j]) - (banyaknya kiri) + (banyaknya kiri <= nums[j]) 
                ans += (long long)pref[j][nums[k-1]-1] * ((n - nums[j-1]) - k + pref[k][nums[j-1]]);
            }
        }
        return ans;
    }
};