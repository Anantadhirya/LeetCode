const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return NULL; }();

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int ans = 0, sm = 0;
        int odd = 0, even = 1;
        for(const auto &i: arr) {
            sm += i;
            if(sm&1) {
                odd++;
                ans += even;
            } else {
                even++;
                ans += odd;
            }
            if(ans > MOD) ans -= MOD;
        }
        return ans % MOD;
    }
};