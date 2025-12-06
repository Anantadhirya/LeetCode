const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dqa, dqi;
        const long long MOD = 1e9 + 7;
        vector<long long> dp(n, 0), pref(n, 0);
        for(int i = 0, j = 0; i < n; i++) {
            while(!dqa.empty() && nums[dqa.back()] <= nums[i]) dqa.pop_back();
            while(!dqi.empty() && nums[dqi.back()] >= nums[i]) dqi.pop_back();
            dqa.push_back(i);
            dqi.push_back(i);
            while(!dqa.empty() && !dqi.empty() && nums[dqa.front()] - nums[dqi.front()] > k) {
                if(dqa.front() == j) dqa.pop_front();
                if(dqi.front() == j) dqi.pop_front();
                j++;
            }
            dp[i] = ((i-1 >= 0 ? pref[i-1] : 0) - (j-2 >= 0 ? pref[j-2] : 0) + MOD + (j == 0)) % MOD;
            pref[i] = (dp[i] + (i-1 >= 0 ? pref[i-1] : 0)) % MOD;
        }
        return dp[n-1];
    }
};