const int inf = INT_MAX;
struct Node {
    int mn = 0, mx = 0;
    int lz = 0;
};

class Solution {
public:
    void prop(int si, vector<Node> &st) {
        if(st[si].lz != 0) {
            st[si].mn += st[si].lz;
            st[si].mx += st[si].lz;
            st[2*si+1].lz += st[si].lz;
            st[2*si+2].lz += st[si].lz;
            st[si].lz = 0;
        }
    }
    void update(int l, int r, int add, int sl, int sr, int si, vector<Node> &st) {
        prop(si, st);
        if(sr < l || r < sl) return;
        if(l <= sl && sr <= r) {
            st[si].lz += add;
            prop(si, st);
            return;
        }
        int sm = (sl+sr)/2;
        update(l, r, add, sl, sm, 2*si+1, st);
        update(l, r, add, sm+1, sr, 2*si+2, st);
        st[si].mn = min(st[2*si+1].mn, st[2*si+2].mn);
        st[si].mx = max(st[2*si+1].mx, st[2*si+2].mx);
    }
    int query(int l, int r, int sl, int sr, int si, vector<Node> &st) {
        prop(si, st);
        if(sr < l || r < sl || 0 < st[si].mn || st[si].mx < 0) return inf;
        if(sl == sr) return sl;
        int sm = (sl+sr)/2;
        int q = query(l, r, sl, sm, 2*si+1, st);
        if(q != inf) return q;
        else return query(l, r, sm+1, sr, 2*si+2, st);
    }
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        map<int, int> lst;
        vector<Node> st(8*n);
        for(int i = 0, q; i < n; i++) {
            update(lst[nums[i]], i, (nums[i]&1 ? 1 : -1), 0, n-1, 0, st);
            lst[nums[i]] = i+1;

            q = query(0, i, 0, n-1, 0, st);
            if(q != inf) ans = max(ans, i-q+1);
        }
        return ans;
    }
};