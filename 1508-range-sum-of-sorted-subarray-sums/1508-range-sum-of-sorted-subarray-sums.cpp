class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> v;
        long long ans = 0;
        const long long MOD = 1e9 + 7;
        for(int i = 0, t; i < n; i++) {
            t = 0;
            for(int j = i; j < n; j++) {
                t += nums[j];
                v.push_back(t);
            }
        }
        sort(v.begin(), v.end());
        for(int i = left-1; i <= right-1; i++) {
            (ans += (long long)v[i]) %= MOD;
        }
        return ans;
    }
};