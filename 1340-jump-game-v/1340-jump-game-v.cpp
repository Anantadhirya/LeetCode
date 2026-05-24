class Solution {
public:
    int query(int l, int r, int sl, int sr, int si, vector<int> &st) {
        if(sr < l || r < sl) return 0;
        if(l <= sl && sr <= r) return st[si];
        int sm = (sl+sr)/2;
        return max(query(l, r, sl, sm, 2*si+1, st), query(l, r, sm+1, sr, 2*si+2, st));
    }
    void update(int i, int x, int sl, int sr, int si, vector<int> &st) {
        if(sl == sr) {
            st[si] = max(st[si], x);
            return;
        }
        int sm = (sl+sr)/2;
        if(i <= sm) update(i, x, sl, sm, 2*si+1, st);
        else update(i, x, sm+1, sr, 2*si+2, st);
        st[si] = max(st[2*si+1], st[2*si+2]);
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> st(4*n, 0);
        vector<pair<int, int>> v(n);
        vector<int> dp(n, 0), l(n, 0), r(n, 0), s;
        for(int i = 0; i < n; i++) {
            v[i] = {arr[i], i};
        }
        for(int i = 0; i < n; i++) {
            while(!s.empty() && arr[s.back()] < arr[i]) s.pop_back();
            l[i] = s.empty() ? 0 : s.back() + 1;
            s.push_back(i);
        }
        s.clear();
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && arr[s.back()] < arr[i]) s.pop_back();
            r[i] = s.empty() ? n-1 : s.back() - 1;
            s.push_back(i);
        }
        for(int i = 0; i < n; i++) {
            l[i] = max(l[i], i-d);
            r[i] = min(r[i], i+d);
        }
        sort(v.begin(), v.end());
        for(int i = 0, j = 0; i < n; i = j) {
            while(j < n && v[j].first == v[i].first) j++;
            for(int k = i, idx; k < j; k++) {
                idx = v[k].second;
                dp[idx] = 1 + query(l[idx], r[idx], 0, n-1, 0, st);
            }
            for(int k = i; k < j; k++) {
                update(v[k].second, dp[v[k].second], 0, n-1, 0, st);
            }
        }
        return st[0];
    }
};