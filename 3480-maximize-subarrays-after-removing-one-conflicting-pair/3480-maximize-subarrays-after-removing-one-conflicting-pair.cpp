class Solution {
public:
    void add(pair<int, int> &a, int b) {
        if(b > a.second) a.second = b;
        if(a.first < a.second) swap(a.first, a.second);
    }
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<pair<int, int>> v(n+1, {0, 0});
        long long init = 0, tmp = 0, ans = 0;
        for(auto &i: conflictingPairs) {
            if(i[0] > i[1]) swap(i[0], i[1]);
            add(v[i[1]], i[0]);
        }
        for(int i = 1; i <= n; i++) {
            add(v[i], v[i-1].first);
            add(v[i], v[i-1].second);
            init += i - v[i].first;
        }
        ans = init;
        for(int i = 1, j; i <= n; i = j) {
            tmp = 0;
            j = i;
            while(j <= n && v[j].first == v[i].first) {
                tmp += (j - v[j].second) - (j - v[j].first);
                j++;
            }
            ans = max(ans, init + tmp);
        }
        return ans;
    }
};