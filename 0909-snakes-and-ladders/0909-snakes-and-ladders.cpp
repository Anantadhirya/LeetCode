class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        const int inf = INT_MAX;
        vector<int> v(n*n);
        vector<vector<int>> adj(n*n);
        vector<int> dp(2*n*n, inf);
        // dp[node][harus ikut tangga/ular di node itu]
        vector<bool> vis(2*n*n, 0);
        priority_queue<pair<int, int>> pq;
        int curr;
        for(int i = 0, j; i < n*n; i++) {
            j = i%n;
            v[i] = board[n-1-i/n][(i/n)&1 ? n-1-j : j];
            if(v[i] != -1) {
                v[i]--;
                adj[v[i]].push_back(i);
            }
        }
        dp[2*(n*n-1)] = 0;
        dp[2*(n*n-1)+1] = 0;
        pq.push({-dp[2*(n*n-1)], 2*(n*n-1)});
        pq.push({-dp[2*(n*n-1)+1], 2*(n*n-1)+1});
        while(!pq.empty()) {
            curr = pq.top().second;
            pq.pop();
            if(vis[curr]) continue;
            vis[curr] = 1;
            if((curr&1) == 0) {
                for(const auto &to: adj[curr/2]) {
                    if(dp[2*to+1] == inf) {
                        dp[2*to+1] = dp[curr];
                        pq.push({-dp[2*to+1], 2*to+1});
                    }
                }
            }
            if(curr&1) {
                for(int i = 1, j; i <= 6; i++) {
                    j = curr/2 - i;
                    if(j >= 0 && dp[2*j] == inf) {
                        dp[2*j] = dp[curr] + 1;
                        if(v[j] == -1) {
                            dp[2*j+1] = dp[curr] + 1;
                            pq.push({-dp[2*j+1], 2*j+1});
                        }
                        pq.push({-dp[2*j], 2*j});
                    }
                }
            }
        }
        return dp[0] == inf ? -1 : dp[0];
    }
};