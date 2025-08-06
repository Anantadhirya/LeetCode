class Solution {
public:
    const int inf = INT_MAX;
    void setup(int si, int sl, int sr, vector<int> &st, vector<pair<int,int>> &v) {
        if(sl == sr) {
            st[si] = v[sl].second;
            return;
        }
        int sm = (sl+sr)/2;
        setup(2*si+1, sl, sm, st, v);
        setup(2*si+2, sm+1, sr, st, v);
        st[si] = min(st[2*si+1], st[2*si+2]);
    }
    int query(int x, int si, int sl, int sr, vector<int> &st, vector<pair<int, int>> &v) {
        if(v[sr].first < x) return inf;
        if(x <= v[sl].first) return st[si];
        int sm = (sl+sr)/2;
        return min(query(x, 2*si+1, sl, sm, st, v), query(x, 2*si+2, sm+1, sr, st, v));
    }
    void update(int x, int si, int sl, int sr, vector<int> &st) {
        if(sl == sr) {
            st[si] = inf;
            return;
        }
        int sm = (sl+sr)/2;
        if(x <= sm) update(x, 2*si+1, sl, sm, st);
        else update(x, 2*si+2, sm+1, sr, st);
        st[si] = min(st[2*si+1], st[2*si+2]);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<pair<int, int>> v(n);
        vector<int> st(4*n), idx(n);
        int ans = 0, q;
        for(int i = 0; i < n; i++) {
            v[i] = {baskets[i], i};
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            idx[v[i].second] = i;
        }
        setup(0, 0, n-1, st, v);
        for(const int &i: fruits) {
            q = query(i, 0, 0, n-1, st, v);
            if(q == inf) ans++;
            else update(idx[q], 0, 0, n-1, st);
        }
        return ans;
    }
};