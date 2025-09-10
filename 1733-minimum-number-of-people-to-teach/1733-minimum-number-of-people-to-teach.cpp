class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<bitset<505>> v(m+1, 0);
        vector<pair<int, int>> f;
        bitset<505> t;
        int ans = INT_MAX;
        for(int i = 1; i <= m; i++) {
            for(const int &j: languages[i-1]) {
                v[i].set(j);
            }
        }
        for(const auto &i: friendships) {
            if((v[i[0]] & v[i[1]]).any()) continue;
            f.push_back({i[0], i[1]});
        }
        for(int i = 1; i <= n; i++) {
            t = 0;
            for(const auto &[a, b]: f) {
                if(!v[a][i]) t.set(a);
                if(!v[b][i]) t.set(b);
            }
            ans = min(ans, (int)t.count());
        }
        return ans;
    }
};