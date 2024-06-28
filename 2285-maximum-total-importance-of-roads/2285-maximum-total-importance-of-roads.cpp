class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        vector<int> cnt(n, 0);
        vector<int> v;
        long long ans = 0;
        for(const auto &i: roads) {
            cnt[i[0]]++;
            cnt[i[1]]++;
        }
        for(int i = 0; i < n; i++) {
            v.push_back(cnt[i]);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            ans += (long long)(i+1) * v[i];
        }
        return ans;
    }
};