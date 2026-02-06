class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = n-1, j = n-1; i >= 0; i--) {
            while(nums[j] > (long long)k*nums[i]) j--;
            ans = max(ans, j-i+1);
        }
        return n - ans;
    }
};