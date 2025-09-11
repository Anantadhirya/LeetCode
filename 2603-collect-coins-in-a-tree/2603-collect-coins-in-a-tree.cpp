class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<int> d(n, 0), d2(n, 0);
        vector<vector<int>> adj(n);
        queue<int> q;
        int ans = 0;
        for(const auto &i: edges) {
            d[i[0]]++;
            d[i[1]]++;
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < n; i++) {
            if(d[i] == 1 && !coins[i]) q.push(i);
        }
        for(int i; !q.empty(); q.pop()) {
            i = q.front();
            d[i] = -1;
            for(const int &to: adj[i]) {
                if(d[to] == -1) continue;
                if(--d[to] <= 1 && !coins[to]) q.push(to);
            }
        }
        for(int i = 0; i < n; i++) {
            if(d[i] == -1) continue;
            d2[i] = 0;
            for(const int &to: adj[i]) d2[i] += (d[to] != -1 && !(coins[to] && d[to] <= 1));
        }
        for(int i = 0; i < n; i++) {
            if(d[i] == -1 || !coins[i] || d[i] > 1) continue;
            d[i] = -1;
            for(const int &to: adj[i]) if(d2[to] <= 1) d[to] = -1;
        }
        for(int i = 0; i < n; i++) {
            ans += (d[i] != -1);
        }
        return ans <= 1 ? 0 : (ans-1)*2;
    }
};