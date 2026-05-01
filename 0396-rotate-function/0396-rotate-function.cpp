class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sm = 0, tmp = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            sm += nums[i];
            tmp += i*nums[i];
        }
        ans = tmp;
        for(int i = n-1; i >= 0; i--) {
            tmp -= n*nums[i];
            tmp += sm;
            ans = max(ans, tmp);
        }
        return ans;
    }
};