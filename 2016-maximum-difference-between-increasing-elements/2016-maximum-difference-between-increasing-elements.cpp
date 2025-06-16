class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0];
        int ans = -1;
        for(const int &i: nums) {
            mn = min(mn, i);
            if(mn < i) ans = max(ans, i - mn);
        }
        return ans;
    }
};