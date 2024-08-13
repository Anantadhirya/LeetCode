class Solution {
public:
    void solve(int i, int sm, int &n, int &target, vector<int> &v, vector<int> &candidates, vector<vector<int>> &ans, map<vector<int>, bool> &vis) {
        if(vis[v]) return;
        vis[v] = 1;
        if(sm == target) ans.push_back(v);
        v.push_back(0);
        for(int j = i; j < n; j++) {
            v.back() = candidates[j];
            if(sm+candidates[j] > target) break;
            solve(j+1, sm+candidates[j], n, target, v, candidates, ans, vis);
        }
        v.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<vector<int>> ans;
        vector<int> v;
        map<vector<int>, bool> vis;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        solve(0, 0, n, target, v, candidates, ans, vis);
        return ans;
    }
};