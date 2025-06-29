class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int ans = 0;
        vector<int> p(n+1);
        p[0] = 1;
        for(int i = 1; i <= n; i++) {
            p[i] = 2*p[i-1] % MOD;
        }
        for(int i = n-1, j = 0; i >= 0; i--) {
            while(j < n && nums[j] + nums[i] <= target) j++;
            // 0..j-1 harus ada 1
            // = total kemungkinan - (0..j-1 nilainya 0 semua)
            ans = ((long long)ans + p[i] - (j <= i ? p[i-j] : 0) + MOD) % MOD;
        }
        return ans;
    }
};