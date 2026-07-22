class Solution {
public:
    int len(pair<int, int> p) {
        return p.second - p.first + 1;
    }
    void build(int sl, int sr, int si, vector<pair<int, int>> &v, vector<int> &st) {
        if(sl == sr) {
            st[si] = len(v[sl]) + len(v[sl+1]);
            return;
        }
        int sm = (sl+sr)/2;
        build(sl, sm, 2*si+1, v, st);
        build(sm+1, sr, 2*si+2, v, st);
        st[si] = max(st[2*si+1], st[2*si+2]);
    }
    int query(int l, int r, int sl, int sr, int si, vector<int> &st) {
        if(sr < l || r < sl) return 0;
        if(l <= sl && sr <= r) return st[si];
        int sm = (sl+sr)/2;
        return max(query(l, r, sl, sm, 2*si+1, st), query(l, r, sm+1, sr, 2*si+2, st));
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size(), k, l, r;
        int cnt = 0, tmp;
        vector<pair<int, int>> v;
        vector<int> ans, st;
        for(char &c: s) {
            cnt += (c == '1');
        }
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') continue;
            if(v.empty() || v.back().second != i-1) {
                v.push_back({i, i});
            }
            v.back().second = i;
        }
        // for(auto [i, j]: v) {
        //     cout << i << " " << j << "\n";
        // }
        k = v.size();
        st.assign(4*(k+1), 0);
        if(0 <= k-2) build(0, k-2, 0, v, st);
        for(auto &i: queries) {
            l = lower_bound(v.begin(), v.end(), pair<int, int>{i[0], -1}) - v.begin();
            r = lower_bound(v.begin(), v.end(), pair<int, int>{i[1]+1, -1}) - v.begin() - 1;
            tmp = cnt;
            if(l <= r-2 && 0 <= k-2) tmp = max(tmp, cnt + query(l, r-2, 0, k-2, 0, st));
            if(0 <= l-1 && l < k && i[0] <= v[l-1].second && v[l].first <= i[1]) {
                tmp = max(tmp, cnt + v[l-1].second-max(i[0], v[l-1].first)+1 + min(i[1], v[l].second)-v[l].first+1);
            }
            if(0 <= r-1 && r < k && i[0] <= v[r-1].second && v[r].first <= i[1]) {
                tmp = max(tmp, cnt + v[r-1].second-max(i[0], v[r-1].first)+1 + min(i[1], v[r].second)-v[r].first+1);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};