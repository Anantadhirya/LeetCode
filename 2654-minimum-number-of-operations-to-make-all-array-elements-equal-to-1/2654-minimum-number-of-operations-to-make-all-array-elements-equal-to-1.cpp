class Solution {
public:
    int gcd(int a, int b) {
        if(a == 0) return b;
        return gcd(b%a, a);
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) cnt1++;
        }
        if(cnt1 > 0) return n - cnt1;
        for(int l = 0, g; l < n; l++) {
            g = 0;
            for(int r = l; r < n; r++) {
                g = gcd(g, nums[r]);
                if(g == 1) {
                    ans = min(ans, r-l + n-1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};