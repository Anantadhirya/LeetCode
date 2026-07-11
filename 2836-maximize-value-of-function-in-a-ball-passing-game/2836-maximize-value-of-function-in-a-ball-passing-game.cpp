class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        vector<pair<int, long long>> nxt(n), ans(n), tmp(n);
        long long ret = 0;
        for(int i = 0; i < n; i++) {
            nxt[i] = {receiver[i], receiver[i]};
            ans[i] = {i, i};
        }
        for(; k > 0; k >>= 1) {
            if(k&1) {
                for(int i = 0; i < n; i++) {
                    ans[i] = {nxt[ans[i].first].first, ans[i].second + nxt[ans[i].first].second};
                }
            }
            for(int i = 0; i < n; i++) {
                tmp[i] = {nxt[nxt[i].first].first, nxt[i].second + nxt[nxt[i].first].second};
            }
            nxt = tmp;
        }
        for(int i = 0; i < n; i++) ret = max(ret, ans[i].second);
        return ret;
    }
};