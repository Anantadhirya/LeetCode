class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 1);
        long long tmp;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = n-1, j = n-1; i >= 0; i--) {
            tmp = (long long)nums[i] * nums[i];
            while(tmp < nums[j]) j--;
            if(tmp == nums[j]) v[i] = 1 + v[j];
            ans = max(ans, v[i]);
        }
        return ans < 2 ? -1 : ans;
    }
};