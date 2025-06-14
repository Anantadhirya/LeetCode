const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> v;
        while(num) {
            v.push_back(num%10);
            num /= 10;
        }
        reverse(v.begin(), v.end());
        int n = v.size(), idx1 = 0, idx2 = 0;
        char c1, c2;
        int mx = 0, mn = 0;
        while(idx1 < n && v[idx1] == 9) idx1++;
        while(idx2 < n && v[idx2] == 0) idx2++;
        c1 = (idx1 == n ? 9 : v[idx1]);
        c2 = (idx2 == n ? 0 : v[idx2]);
        for(int i = 0; i < n; i++) {
            mx = 10*mx + (v[i] == c1 ? 9 : v[i]);
            mn = 10*mn + (v[i] == c2 ? 0 : v[i]);
        }
        return mx - mn;
    }
};