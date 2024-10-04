class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        int ans = 0;
        set<int> s;
        map<int, int> lst;
        dp[n-1][0] = dp[n-1][1] = 1;
        for(int i = n-2; i >= 0; i--) {
            s.insert(arr[i+1]);
            lst[arr[i+1]] = i+1;
            auto it = s.lower_bound(arr[i]);
            if(it != s.end()) {
                dp[i][0] |= dp[lst[*it]][1];
            }
            if(*it == arr[i]) it++;
            if(it != s.begin()) {
                it--;
                dp[i][1] |= dp[lst[*it]][0];
            }
        }
        for(int i = 0; i < n; i++) {
            ans += dp[i][0];
        }
        return ans;
    }
};