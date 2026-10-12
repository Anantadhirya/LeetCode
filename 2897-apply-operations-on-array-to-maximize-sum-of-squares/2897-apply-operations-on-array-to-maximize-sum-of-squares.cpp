class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> v(n, 0);
        for(int i = 1, cnt; i <= mx; i <<= 1) {
            cnt = 0;
            for(int &j: nums) {
                if(j&i) cnt++;
            }
            for(int j = 0; j < cnt; j++) {
                v[j] += i;
            }
        }
        long long ans = 0;
        long long MOD = 1e9 + 7;
        for(int i = 0; i < k; i++) {
            (ans += (long long)v[i]*v[i] % MOD) %= MOD;
        }
        return ans;
    }
};