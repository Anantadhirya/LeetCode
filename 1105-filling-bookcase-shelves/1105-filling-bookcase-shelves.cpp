class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = books.size();
        const int inf = INT_MAX;
        vector<int> dp(n+1, inf);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1, t = 0, h = 0; j <= n; j++) {
                t += books[j-1][0];
                h = max(h, books[j-1][1]);
                if(t > shelfWidth) break;
                dp[j] = min(dp[j], dp[i] + h);
            }
        }
        return dp[n];
    }
};