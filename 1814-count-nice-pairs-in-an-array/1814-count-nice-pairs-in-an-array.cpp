class Solution {
public:
    int rev(int x) {
        int ret = 0;
        while(x > 0) {
            ret = 10*ret + x%10;
            x /= 10;
        }
        return ret;
    }
    int countNicePairs(vector<int>& nums) {
        int ans = 0;
        const int MOD = 1e9 + 7;
        map<int, int> cnt;
        for(int &i: nums) {
            (ans += cnt[i - rev(i)]++) %= MOD;
        }
        return ans;
    }
};