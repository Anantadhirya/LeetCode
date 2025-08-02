class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> m;
        int mn = basket1[0], n;
        long long ans = 0;
        vector<int> v[2];
        for(const int &i: basket1) m[i]++, mn = min(mn, i);
        for(const int &i: basket2) m[i]--, mn = min(mn, i);
        for(const auto &[i, c]: m) {
            if(c&1) return -1;
            if(c != 0) 
                for(int j = abs(c); j > 0; j -= 2) v[c > 0].push_back(i);
        }
        if(v[0].size() != v[1].size()) return -1;
        n = v[0].size();
        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end());
        for(int i = 0; i < n; i++) {
            ans += min(2*mn, min(v[0][i], v[1][n-1-i]));
        }
        return ans;
    }
};