class Solution {
public:
    int minJumps(vector<int>& nums) {
        const int inf = INT_MAX;
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());
        vector<int> f(mx+1, -1);
        vector<vector<int>> adj(mx+1);

        int cur;
        vector<int> dist(n, inf);
        vector<bool> vis(n, 0);
        queue<int> q;

        for(long long i = 2; i <= mx; i++) {
            if(f[i] != -1) continue;
            for(long long j = i*i; j <= mx; j += i) {
                f[j] = i;
            }
        }
        for(int i = 0, x, p; i < n; i++) {
            for(x = nums[i]; f[x] != -1; ) {
                p = f[x];
                adj[p].push_back(i);
                while(x % p == 0) x /= p;
            }
            if(x != 1) adj[x].push_back(i);
        }

        auto add = [&](int i, int d) -> void {
            if(vis[i]) return;
            dist[i] = d;
            vis[i] = 1;
            q.push(i);
        };
        add(0, 0);
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            if(cur+1 < n) add(cur+1, dist[cur]+1);
            if(cur-1 >= 0) add(cur-1, dist[cur]+1);
            if(f[nums[cur]] == -1) {
                for(int to: adj[nums[cur]]) {
                    add(to, dist[cur]+1);
                }
                adj[nums[cur]].clear();
            }
        }
        return dist[n-1];
    }
};