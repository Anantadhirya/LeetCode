class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int MX = 1e4;
        const int MOD = 1e9 + 7;
        int k = ceil(1.0*log(maxValue)/log(2))+1;
        bitset<MX+5> composit;
        vector<int> primes;
        vector<int> dp(k+1, 0);
        int ans = 0, tmp;
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                (dp[j] += dp[j-1]) %= MOD; 
            }
        }
        for(int i = 2; i*i <= maxValue; i++) {
            if(composit[i]) continue;
            primes.push_back(i);
            for(int j = i*i; j <= maxValue; j += i) composit[j] = 1;
        }
        for(int i = 1, x, p; i <= maxValue; i++) {
            tmp = 1;
            x = i;
            for(int j = 0; j < primes.size() && primes[j] * primes[j] <= x; j++) {
                p = 0;
                while(x % primes[j] == 0) x /= primes[j], p++;
                tmp = ((long long)tmp * dp[p]) % MOD;
            }
            if(x != 1) tmp = ((long long)tmp * dp[1]) % MOD;
            (ans += tmp) %= MOD;
        }
        return ans;
    }
};