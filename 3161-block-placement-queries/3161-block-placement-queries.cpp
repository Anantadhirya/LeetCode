class Solution {
public:
    void update(int i, int x, int sl, int sr, int si, vector<int> &st) {
        if(sl == sr) {
            st[si] = x;
            return;
        }
        int sm = (sl+sr)/2;
        if(i <= sm) update(i, x, sl, sm, 2*si+1, st);
        else update(i, x, sm+1, sr, 2*si+2, st);
        st[si] = max(st[2*si+1], st[2*si+2]);
    }
    int query(int l, int r, int sl, int sr, int si, vector<int> &st) {
        if(sr < l || r < sl) return 0;
        if(l <= sl && sr <= r) return st[si];
        int sm = (sl+sr)/2;
        return max(query(l, r, sl, sm, 2*si+1, st), query(l, r, sm+1, sr, 2*si+2, st));
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = 3*queries.size()+5;
        set<int> obstacles;
        vector<int> st(4*n, 0);
        vector<bool> ans;
        obstacles.insert(0);
        obstacles.insert(n);
        update(0, n, 0, n, 0, st);
        for(auto i: queries) {
            if(i[0] == 1) {
                auto it = obstacles.upper_bound(i[1]);
                update(i[1], *it - i[1], 0, n, 0, st);
                --it;
                update(*it, i[1] - *it, 0, n, 0, st);
                obstacles.insert(i[1]);
            } else if(i[0] == 2) {
                ans.push_back(query(0, i[1] - i[2], 0, n, 0, st) >= i[2]);
            }
        }
        return ans;
    }
};