class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int inf = INT_MAX;
        vector<vector<int>> dp(n+1, vector<int>(3, inf));
        dp[0][0] = 0;
        for(int i = 0, j = 0, sm = 0; i < n; i++) {
            sm += arr[i];
            while(sm > target) sm -= arr[j++];

            for(int c = 0; c <= 2; c++) {
                dp[i+1][c] = min(dp[i+1][c], dp[i][c]);

                if(sm == target && c > 0 && dp[j][c-1] != inf) {
                    dp[i+1][c] = min(dp[i+1][c], dp[j][c-1] + i-j+1);
                }
            }
        }
        return dp[n][2] == inf ? -1 : dp[n][2];
    }
};