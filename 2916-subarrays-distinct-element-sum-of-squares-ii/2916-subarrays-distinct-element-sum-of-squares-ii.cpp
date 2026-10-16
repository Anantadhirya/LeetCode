#define LL long long

class Solution {
public:
    pair<LL, int> query(int l, int r, int si, int sl, int sr, vector<pair<LL, int>> &st) {
        if(sr < l || r < sl) return {0, 0};
        if(l <= sl && sr <= r) return st[si];
        int sm = (sl+sr)/2;
        auto ql = query(l, r, 2*si+1, sl, sm, st);
        auto qr = query(l, r, 2*si+2, sm+1, sr, st);
        return {ql.first + qr.first, ql.second + qr.second};
    }
    void update(int i, pair<LL, int> val, int si, int sl, int sr, vector<pair<LL, int>> &st) {
        if(sl == sr) {
            st[si] = val;
            return;
        }
        int sm = (sl+sr)/2;
        if(i <= sm) update(i, val, 2*si+1, sl, sm, st);
        else update(i, val, 2*si+2, sm+1, sr, st);
        st[si].first = st[2*si+1].first + st[2*si+2].first;
        st[si].second = st[2*si+1].second + st[2*si+2].second;
    }
    int sumCounts(vector<int>& nums) {
        // x4, x3, x2, x1, x0
        // x0*1 + x1*3 + x2*5 + x3*7 + x4*9
        const LL MOD = 1e9 + 7;
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<pair<LL, int>> st(4*n, {0, 0});
        vector<int> lst(mx+1, -1);
        LL sm = 0, ans = 0;
        pair<LL, int> q;
        for(int r = 0; r < n; r++) {
            q = query(lst[nums[r]]+1, r-1, 0, 0, n-1, st);
            sm += q.first*2;
            update(r, {r+1, 1}, 0, 0, n-1, st);

            // delete last
            if(lst[nums[r]] != -1) {
                sm -= (LL)(lst[nums[r]]+1) * (q.second*2+1);
                update(lst[nums[r]], {0, 0}, 0, 0, n-1, st);
            }

            // add current
            sm += (r+1);

            (ans += sm) %= MOD;
            lst[nums[r]] = r;
        }
        return ans;
    }
};