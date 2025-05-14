const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> mul(vector<vector<int>> &a, vector<vector<int>> &b) {
        vector<vector<int>> ret(26, vector<int>(26, 0));
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                for(int k = 0; k < 26; k++) {
                    (ret[i][j] += (long long)a[i][k] * b[k][j] % MOD) %= MOD; 
                }
            }
        }
        return ret;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> cnt(26, 0);
        vector<vector<int>> mat, tmp;
        int ans = 0;
        for(const auto &i: s) {
            cnt[i-'a']++;
        }
        mat = tmp = vector<vector<int>>(26, vector<int>(26, 0));
        for(int i = 0; i < 26; i++) {
            mat[i][i] = 1;
            for(int j = 1; j <= nums[i]; j++) {
                tmp[(i+j)%26][i] = 1;
            }
        }
        while(t) {
            if(t&1) {
                mat = mul(mat, tmp);
            }
            tmp = mul(tmp, tmp);
            t >>= 1;
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                (ans += (long long)mat[i][j] * cnt[j] % MOD) %= MOD;
            }
        }
        return ans;
    }
};