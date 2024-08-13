class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> cnt(n, 0);
        vector<vector<int>> adj(n);
        vector<int> ans;
        int idx = 0;
        for(const auto &i: prerequisites) {
            adj[i[1]].push_back(i[0]);
            cnt[i[0]]++;
        }
        for(int i = 0; i < n; i++) {
            if(cnt[i] == 0) ans.push_back(i);
        }
        while(idx < ans.size()) {
            for(const auto &to: adj[ans[idx]]) {
                cnt[to]--;
                if(cnt[to] == 0) {
                    ans.push_back(to);
                }
            }
            idx++;
        }
        if(ans.size() == n) return ans;
        else return {};
    }
};