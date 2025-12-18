class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long tmp = 0, ans = 0, pref = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++) {
            tmp += (long long)prices[i] * strategy[i];
        }
        for(int i = 0; i < k/2; i++) {
            pref += (long long)prices[i+k/2] * (1 - strategy[i+k/2]) + (long long)prices[i] * (0 - strategy[i]);
        }
        ans = max(tmp, tmp + pref);
        for(int i = k; i < n; i++) {
            pref += (long long)prices[i] * (1 - strategy[i]);
            pref += (long long)prices[i-k/2] * (0 - 1);
            pref += (long long)prices[i-k] * (strategy[i-k] - 0);
            ans = max(ans, tmp+pref);
        }
        return ans;
    }
};