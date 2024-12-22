class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int n = heights.size(), m = queries.size();
        vector<int> ans(m);
        vector<pair<int, int>> v(n);
        vector<vector<int>> q;
        set<int> s;
        for(int i = 0; i < n; i++) {
            v[i] = {heights[i], i};
        }
        for(int i = 0, u, v; i < m; i++) {
            u = queries[i][0];
            v = queries[i][1];
            if(v < u) swap(u, v);
            if(u == v || heights[u] < heights[v]) ans[i] = v;
            else q.push_back({heights[u], v, i});
            // leftmost index j > i[1] such that heights[j] > i[0]
        }
        sort(v.begin(), v.end());
        sort(q.begin(), q.end());
        for(int i = q.size()-1, j = n-1; i >= 0; i--) {
            while(j >= 0 && v[j].first > q[i][0]) s.insert(v[j--].second);
            auto it = s.upper_bound(q[i][1]);
            ans[q[i][2]] = (it == s.end() ? -1 : *it);
        }
        return ans;
    }
};