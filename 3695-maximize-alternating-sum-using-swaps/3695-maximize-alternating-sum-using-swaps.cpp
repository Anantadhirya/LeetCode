class Solution {
public:
    int fp(int i, vector<int> &par) {
        if(par[i] == i) return i;
        return par[i] = fp(par[i], par);
    }
    void join(int u, int v, vector<int> &par) {
        u = fp(u, par);
        v = fp(v, par);
        par[u] = v;
    }
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();
        vector<int> par(n);
        vector<vector<int>> v(n), cnt(n, vector<int>(2, 0));
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
        for(auto &i: swaps) {
            join(i[0], i[1], par);
        }
        for(int i = 0, j; i < n; i++) {
            j = fp(i, par);
            v[j].push_back(nums[i]);
            cnt[j][i&1]++;
        }
        for(int i = 0; i < n; i++) {
            if(fp(i, par) != i) continue;
            sort(v[i].begin(), v[i].end());
            for(int j = 0; j < cnt[i][1]; j++) {
                ans -= (long long)v[i][j];
            }
            for(int j = 0; j < cnt[i][0]; j++) {
                ans += (long long)v[i][cnt[i][1]+j];
            }
        }
        return ans;
    }
};