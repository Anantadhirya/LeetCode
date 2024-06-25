class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        const long long MOD = 1e9 + 7;
        unordered_map<int, int> fi;
        int n = nums.size();
        vector<long long> dp(n+1, 0);
        long long pref = 0;
        stack<int> s;
        dp[0] = pref = 1;
        for(int i = 1; i <= n; i++) {
            if(!fi.count(nums[i-1])) fi[nums[i-1]] = i;
            while(!s.empty() && fi[nums[i-1]] <= s.top()) {
                pref = (pref - dp[s.top()] + MOD) % MOD;
                s.pop();
            }
            dp[i] = pref;
            pref = (pref + dp[i]) % MOD;
            s.push(i);
        }
        return dp[n];
    }
};