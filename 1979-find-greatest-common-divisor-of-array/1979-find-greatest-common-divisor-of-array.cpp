class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn = nums[0], mx = nums[0];
        for(int &i: nums) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
        return __gcd(mn, mx);
    }
};