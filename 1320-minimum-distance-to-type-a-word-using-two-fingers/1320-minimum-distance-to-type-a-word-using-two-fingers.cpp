class Solution {
public:
    int dist(int a, int b) {
        int ai = a/6, aj = a%6;
        int bi = b/6, bj = b%6;
        return abs(ai-bi) + abs(aj-bj);
    }
    void ms(int &a, int b) {
        a = min(a, b);
    }
    int minimumDistance(string word) {
        const int inf = INT_MAX;
        int n = word.size(), ans = inf;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(26, vector<int>(26, inf)));
        dp[0] = vector<vector<int>>(26, vector<int>(26, 0));
        for(int i = 0, c; i < n; i++) {
            c = word[i]-'A';
            for(int a = 0; a < 26; a++) {
                for(int b = 0; b < 26; b++) {
                    if(dp[i][a][b] == inf) continue;
                    ms(dp[i+1][c][b], dp[i][a][b] + dist(a, c));
                    ms(dp[i+1][a][c], dp[i][a][b] + dist(b, c));
                }
            }
        }
        for(int a = 0; a < 26; a++) {
            for(int b = 0; b < 26; b++) {
                ms(ans, dp[n][a][b]);
            }
        }
        return ans;
    }
};