class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        const int MX = 1e4;
        vector<int> dp(2*MX+5, 0);
        int ans = 0;
        for(int &i: arr) {
            i += MX;
            if(0 <= i-difference && i-difference < 2*MX+5) dp[i] = max(dp[i], dp[i-difference]+1);
            else dp[i] = max(dp[i], 1);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};