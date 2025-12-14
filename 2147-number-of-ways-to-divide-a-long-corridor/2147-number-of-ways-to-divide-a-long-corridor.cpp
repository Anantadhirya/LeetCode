class Solution {
public:
    int numberOfWays(string corridor) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> idx;
        int n = corridor.size();
        const long long MOD = 1e9 + 7;
        long long ans = 1;
        for(int i = 0; i < n; i++) {
            if(corridor[i] == 'S') {
                idx.push_back(i);
            }
        }
        n = idx.size();
        if(n % 2 == 1 || n == 0) return 0;
        for(int i = 2; i < n; i += 2) {
            (ans *= (long long)idx[i] - idx[i-1]) %= MOD;
        }
        return ans;
    }
};