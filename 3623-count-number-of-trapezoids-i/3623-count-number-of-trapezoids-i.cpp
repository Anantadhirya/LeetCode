class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1e9 + 7;
        int n = points.size();
        for(auto &i: points) swap(i[0], i[1]);
        sort(points.begin(), points.end());
        int up = 0, ans = 0, cnt, comb;
        for(int i = 0, j = 0; i < n; i = j) {
            while(j < n && points[i][0] == points[j][0]) j++;
            cnt = j-i;
            comb = (long long)cnt*(cnt-1)/2 % MOD;
            (ans += (long long)comb * up % MOD) %= MOD;
            (up += comb) %= MOD;
        }
        return ans;
    }
};