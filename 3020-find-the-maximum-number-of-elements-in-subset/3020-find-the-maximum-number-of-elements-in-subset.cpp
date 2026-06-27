class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long, int> cnt, dp;
        int ans = 0;
        for(auto &i: nums) {
            cnt[i]++;
        }
        ans = max(ans, cnt[1] - (1 - (cnt[1] % 2)));
        for(auto it = cnt.end(); it != cnt.begin(); ) {
            it--;
            auto val = it->first;
            if(val == 1) continue;
            dp[val] = 1;
            if(cnt[val] >= 2 && cnt.count(val * val)) {
                dp[val] = 2 + dp[val * val];
            }
            ans = max(ans, dp[val]);
        }
        return ans;
    }
};