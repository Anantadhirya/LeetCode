class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        const long long inf = LLONG_MAX;
        int n = nums.size();
        vector<long long> cost(n);
        vector<vector<long long>> dp(n+1, vector<long long>(k+1, inf));
        set<pair<int, int>> s1, s2;
        long long sm1 = 0, sm2 = 0;
        for(int i = 0; i < n; i++) {
            if(s1.empty() || nums[i] <= s1.rbegin()->first) s1.insert({nums[i], i}), sm1 += (long long)nums[i];
            else s2.insert({nums[i], i}), sm2 += (long long)nums[i];
            if(i-x >= 0) {
                if(s1.count({nums[i-x], i-x})) {
                    s1.erase({nums[i-x], i-x});
                    sm1 -= (long long)nums[i-x];
                } else {
                    s2.erase({nums[i-x], i-x});
                    sm2 -= (long long)nums[i-x];
                }
            }

            // s1 size should be (x+1)/2
            while(!s2.empty() && s1.size() < (x+1)/2) {
                auto it = s2.begin();
                sm1 += (long long)it->first;
                s1.insert(*it);
                sm2 -= (long long)it->first;
                s2.erase(it);
            }
            while(s1.size() > (x+1)/2) {
                auto it = s1.end();
                it--;
                sm2 += (long long)it->first;
                s2.insert(*it);
                sm1 -= (long long)it->first;
                s1.erase(it);
            }

            if(i-x+1 >= 0) {
                cost[i] = s1.rbegin()->first * ((x+1)/2 - x/2) - sm1 + sm2;
            }
        }
        // for(int i = 0; i < n; i++) {
        //     cout << cost[i] << " \n"[i==n-1];
        // }
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i][j] = dp[i-1][j];
                if(i-x+1 >= 1 && j >= 1 && dp[i-x][j-1] != inf) {
                    dp[i][j] = min(dp[i][j], dp[i-x][j-1] + cost[i-1]);
                }
            }
        }
        return dp[n][k];
    }
};