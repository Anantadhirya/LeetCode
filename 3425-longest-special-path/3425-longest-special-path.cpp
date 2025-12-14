class Solution {
public:
    void dfs(int curr, int from, int idx, vector<int> &nums, vector<vector<pair<int, int>>> &adj, vector<int> &pref, vector<int> &lst, pair<int, int> &ans) {
        idx = max(idx, lst[nums[curr]]);
        ans = max(ans, {(pref.empty() ? 0 : pref.back()) - (-1 < idx && idx < pref.size() ? pref[idx] : 0), -(pref.size() - idx)});
        
        int l = lst[nums[curr]];
        lst[nums[curr]] = pref.size();
        for(auto [to, w]: adj[curr]) {
            if(to == from) continue;
            pref.push_back((pref.empty() ? 0 : pref.back()) + w);
            dfs(to, curr, idx, nums, adj, pref, lst, ans);
            pref.pop_back();
        }
        lst[nums[curr]] = l;
    }
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        pair<int, int> ans = {-1, -1};
        vector<int> lst(5e4+1, -1), pref;
        vector<vector<pair<int, int>>> adj(n);
        for(auto i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        dfs(0, -1, -1, nums, adj, pref, lst, ans);
        return {ans.first, -ans.second};
    }
};