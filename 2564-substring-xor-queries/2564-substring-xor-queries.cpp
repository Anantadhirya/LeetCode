class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        map<int, pair<int, pair<int, int>>> ans;
        int n = s.size();
        for(int l = 0, v; l < n; l++) {
            v = 0;
            for(int r = l; r < min(n, l+30); r++) {
                v = 2*v + (s[r] == '1');
                if(!ans.count(v)) ans[v] = {INT_MAX, {-1, -1}};
                ans[v] = min(ans[v], {r-l+1, {l, r}});
            }
        }
        int v;
        for(auto &i: queries) {
            v = i[0] ^ i[1];
            if(!ans.count(v)) i = {-1, -1};
            else i[0] = ans[v].second.first, i[1] = ans[v].second.second;
        }
        return queries;
    }
};