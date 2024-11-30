class Solution {
public:
    void dfs(int curr, unordered_map<int, vector<int>> &adj, vector<vector<int>> &ans) {
        for(int to; !adj[curr].empty(); ) {
            to = adj[curr].back();
            adj[curr].pop_back();
            dfs(to, adj, ans);
            ans.push_back({to, curr});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> cnt;
        int start = pairs[0][0];
        vector<vector<int>> ans;
        for(auto &i: pairs) {
            cnt[i[0]]++;
            cnt[i[1]]--;
            adj[i[1]].push_back(i[0]);
        }
        for(auto &[i, c]: cnt) {
            if(c < 0) start = i;
        }
        dfs(start, adj, ans);
        return ans;
    }
};