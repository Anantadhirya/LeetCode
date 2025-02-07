const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return NULL; }();

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size(), tmp = 0;
        vector<int> ans(n);
        unordered_map<int, int> color, cnt;
        cnt[0] = limit+5;
        for(int i = 0, x, y; i < n; i++) {
            x = queries[i][0], y = queries[i][1];
            if(--cnt[color[x]] == 0) tmp--;
            color[x] = y;
            if(cnt[color[x]]++ == 0) tmp++;
            ans[i] = tmp;
        }
        return ans;
    }
};