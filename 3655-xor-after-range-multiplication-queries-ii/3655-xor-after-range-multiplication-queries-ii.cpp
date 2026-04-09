class Solution {
public:
    const int MOD = 1e9 + 7;
    int pangkat(int a, int b) {
        int ret = 1;
        while(b > 0) {
            if(b&1) ret = ((long long)ret * a) % MOD;
            a = ((long long)a*a) % MOD;
            b >>= 1;
        }
        return ret;
    }
    int inv(int x) {
        return pangkat(x, MOD-2);
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int sq = sqrt(n);
        vector<vector<tuple<int, int, int>>> q(sq);
        vector<int> v(n);
        int l, r, k, x, ans = 0;
        for(auto &i: queries) {
            l = i[0], r = i[1], k = i[2], x = i[3];
            if(k >= sq) {
                for(int i = l; i <= r; i += k) nums[i] = ((long long)nums[i] * x) % MOD;
            } else q[k].push_back({l, r, x});
        }
        for(int j = 1; j < sq; j++) {
            for(int i = 0; i < n; i++) v[i] = 1;
            for(auto &[l, r, x]: q[j]) {
                v[l] = ((long long)v[l] * x) % MOD;
                r = r - (r-l)%j + j;
                if(r < n) v[r] = ((long long)v[r] * inv(x)) % MOD;
            }
            for(int i = 0; i < n; i++) {
                if(i-j >= 0) v[i] = ((long long)v[i] * v[i-j]) % MOD;
                nums[i] = ((long long)nums[i] * v[i]) % MOD;
            }
        }
        for(int i = 0; i < n; i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};