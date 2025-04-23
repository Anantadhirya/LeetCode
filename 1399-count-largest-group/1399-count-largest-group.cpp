const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> cnt;
        for(int i = 1, j; i <= n; i++) {
            j = 0;
            for(int k = i; k > 0; k /= 10) j += k%10;
            cnt[j]++;
        }
        int ans = 0, mx = 0;
        for(const auto &[_, i]: cnt) {
            if(i > mx) mx = i, ans = 1;
            else if(i == mx) ans++;
        }
        return ans;
    }
};