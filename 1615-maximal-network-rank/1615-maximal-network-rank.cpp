class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n, 0);
        set<pair<int, int>> s;
        for(auto i: roads) {
            cnt[i[0]]++;
            cnt[i[1]]++;
            if(i[0] > i[1]) swap(i[0], i[1]);
            s.insert({i[0], i[1]});
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                ans = max(ans, cnt[i] + cnt[j] - (int)s.count({i, j}));
            }
        }
        return ans;
    }
};