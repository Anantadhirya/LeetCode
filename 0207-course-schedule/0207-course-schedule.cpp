class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = numCourses;
        vector<int> cnt(n, 0);
        vector<vector<int>> adj(n);
        queue<int> q;
        for(const auto &i: prerequisites) {
            adj[i[0]].push_back(i[1]);
            cnt[i[1]]++;
        }
        for(int i = 0; i < n; i++) {
            if(cnt[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            for(const auto &to: adj[q.front()]) {
                cnt[to]--;
                if(cnt[to] == 0) q.push(to);
            }
            q.pop();
        }
        for(int i = 0; i < n; i++) {
            if(cnt[i] != 0) return 0;
        }
        return 1;
    }
};