class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> v(1, 1);
        int n = nums.size(), ans = 0, k;
        for(int i = 1; i < n; i++) {
            if(nums[i-1] < nums[i]) v.back()++;
            else v.push_back(1);
        }
        k = v.size();
        for(const int &i: v) ans = max(ans, i/2);
        for(int i = 0; i+1 < k; i++) {
            ans = max(ans, min(v[i], v[i+1]));
        }
        return ans;
    }
};