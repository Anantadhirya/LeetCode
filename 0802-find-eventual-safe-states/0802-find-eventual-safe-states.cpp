class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> cnt(n, 0);
        vector<vector<int>> adj(n);
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < n; i++) {
            for(const int &to: graph[i]) {
                cnt[i]++;
                adj[to].push_back(i);
            }
            if(cnt[i] == 0) q.push(i);
        }
        for(int i; !q.empty(); ) {
            i = q.front();
            q.pop();
            ans.push_back(i);
            for(const int &to: adj[i]) {
                if(--cnt[to] == 0) q.push(to);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};