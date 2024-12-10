class Solution {
public:
    int maximumLength(string s) {
        ios_base::sync_with_stdio(false); cin.tie(0);
        int ans = -1, n = s.size();
        vector<vector<int>> v(26, vector<int>(3, -1));
        for(int i = 0, j = 0, c; i < n; i++) {
            if(i > 0 && s[i] != s[i-1]) j = 0;
            j++;
            c = s[i] - 'a';
            v[c][0] = max(v[c][0], j);
            if(v[c][0] > v[c][1]) swap(v[c][0], v[c][1]);
            if(v[c][1] > v[c][2]) swap(v[c][1], v[c][2]);
            ans = max(ans, v[c][0]);
        }
        return ans;
    }
};