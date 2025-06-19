class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = nums[0], ans = 1;
        for(const int &i: nums) {
            if(i - l > k) {
                ans++;
                l = i;
            }
        }
        return ans;
    }
};