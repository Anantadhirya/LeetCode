const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26, 0);
        for(const auto &i: s) {
            v[i-'a']++;
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 26 - 2, to; i >= 0; i--) {
            if(v[i] >= v[i+1]) {
                to = max(0, v[i+1] - 1);
                ans += (v[i] - to);
                v[i] = to;
            }
        }
        return ans;
    }
};