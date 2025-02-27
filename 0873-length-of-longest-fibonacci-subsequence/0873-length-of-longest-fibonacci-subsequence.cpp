class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 2;
        for(int i = 2; i < n; i++) {
            for(int j = i-1, k = 0; j >= 0; j--) {
                while(k < j && arr[k] < arr[i] - arr[j]) k++;
                if(k < j && arr[k] + arr[j] == arr[i]) {
                    dp[j][i] = max(dp[j][i], dp[k][j] + 1);
                    ans = max(ans, dp[j][i]);
                }
            }
        }
        return ans >= 3 ? ans : 0;
    }
};