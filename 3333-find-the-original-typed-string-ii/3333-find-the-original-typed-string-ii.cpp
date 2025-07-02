const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int MOD = 1e9 + 7;
        int n = word.size(), m;
        vector<int> v(1, 1);
        int ans = 1;

        for(int i = 1; i < n; i++) {
            if(word[i] == word[i-1]) v.back()++;
            else v.push_back(1);
        }
        m = v.size();
        for(const int &i: v) ans = ((long long)ans * i) % MOD;
        if(m >= k) return ans;

        vector<int> dp(k, 0), pref(k, 1);
        for(const int &i: v) {
            for(int j = 1; j <= k-1; j++) {
                dp[j] = ((long long)pref[j-1] - (j-i-1 >= 0 ? pref[j - i - 1] : 0) + MOD) % MOD;
            }
            pref[0] = 0;
            for(int j = 1; j <= k-1; j++) {
                pref[j] = (dp[j] + pref[j-1]) % MOD;
            }
        }
        return ((long long)ans - pref[k-1] + MOD) % MOD;
    }
};