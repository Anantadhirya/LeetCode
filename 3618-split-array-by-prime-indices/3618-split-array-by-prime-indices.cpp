class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<bool> prime(n, 1);
        prime[0] = prime[1] = 0;
        for(int i = 0; i < n; i++) {
            ans += (long long)nums[i] * (prime[i] ? 1 : -1);
            if(prime[i]) {
                for(long long j = (long long)i*i; j < n; j += i) prime[j] = 0;
            }
        }
        return abs(ans);
    }
};