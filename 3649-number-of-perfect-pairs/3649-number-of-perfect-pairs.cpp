class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        // R-x <= x && R+x >= R
        // R <= 2*x
        int n = nums.size();
        long long ans = 0;
        for(auto &i: nums) i = abs(i);
        sort(nums.begin(), nums.end());
        for(int i = 0, j = 0; i < n; i++) {
            while(2*nums[j] < nums[i]) j++;
            ans += (long long)i-j;
        }
        return ans;
    }
};