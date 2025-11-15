class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> pos;
        int n = s.size();
        int sq = ceil(sqrt(n+.0)) + 2;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') pos.push_back(i);
            for(int j = 0; j <= min(sq, (int)pos.size()); j++) {
                int l = (j == pos.size() ? -1 : pos[pos.size() - j - 1]);
                int cnt1r = (j == 0 ? 0 : i - pos[pos.size() - j] + 1) - j;
                int r = (j == 0 ? i : pos[pos.size() - j] - max(0, (j*j - cnt1r)));
                // if(l < r) cout << i << " " << j << " -> " << l << " " << r << "\n";
                if(l < r) ans += r-l;
            }
        }
        return ans;
    }
};