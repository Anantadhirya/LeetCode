class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = 0, cnt = 0, ans = 0;
        for(const auto &i: nums) {
            k += i;
        }
        for(int i = 0; i < k; i++) {
            cnt += nums[i];
        }
        for(int i = n-1; i >= 0; i--) {
            cnt += nums[i] - nums[(i+k)%n];
            ans = max(ans, cnt);
        }
        return k - ans;
    }
};