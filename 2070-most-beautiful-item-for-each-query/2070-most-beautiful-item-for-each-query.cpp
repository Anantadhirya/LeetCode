class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        vector<pair<int, int>> q(m);
        vector<int> ans(m);
        int j = 0, mx = 0;
        for(int i = 0; i < m; i++) {
            q[i] = {queries[i], i};
        }
        sort(items.begin(), items.end());
        sort(q.begin(), q.end());
        for(const auto &[v, i]: q) {
            while(j < n && items[j][0] <= v) mx = max(mx, items[j++][1]);
            ans[i] = mx;
        }
        return ans;
    }
};