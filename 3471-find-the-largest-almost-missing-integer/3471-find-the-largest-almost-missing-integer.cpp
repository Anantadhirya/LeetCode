class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(51, 0);

        // case k = n
        if(k == n) return *max_element(nums.begin(), nums.end());
        
        for(int &i: nums) cnt[i]++;
        
        // case k = 1
        if(k == 1) {
            for(int i = 50; i >= 0; i--) {
                if(cnt[i] == 1) return i;
            }
            return -1;
        }

        // case 1 < k < n
        if(nums[0] < nums[n-1]) swap(nums[0], nums[n-1]);
        if(cnt[nums[0]] == 1) return nums[0];
        if(cnt[nums[n-1]] == 1) return nums[n-1];
        return -1;
    }
};