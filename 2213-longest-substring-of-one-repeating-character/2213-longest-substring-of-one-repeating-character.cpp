struct Node {
    int val;
    int len;
    pair<char, int> l, r;
};

Node merge(Node a, Node b) {
    Node ret;
    ret.l = (a.l.second == a.len && a.l.first == b.l.first ? pair<char, int>{a.l.first, a.l.second + b.l.second} : a.l);
    ret.r = (b.r.second == b.len && a.r.first == b.r.first ? pair<char, int>{b.r.first, a.r.second + b.r.second} : b.r);
    ret.val = max({a.val, b.val, ret.l.second, ret.r.second});
    ret.len = a.len + b.len;
    if(a.r.first == b.l.first) ret.val = max(ret.val, a.r.second + b.l.second);
    return ret;
}

class Solution {
public:
    void build(int sl, int sr, int si, vector<Node> &st, string &s) {
        if(sl == sr) {
            st[si].val = 1;
            st[si].len = 1;
            st[si].l = st[si].r = {s[sl], 1};
            return;
        }
        int sm = (sl+sr)/2;
        build(sl, sm, 2*si+1, st, s);
        build(sm+1, sr, 2*si+2, st, s);
        st[si] = merge(st[2*si+1], st[2*si+2]);
    }
    void update(int i, char c, int sl, int sr, int si, vector<Node> &st) {
        if(sl == sr) {
            st[si].val = 1;
            st[si].l = st[si].r = {c, 1};
            return;
        }
        int sm = (sl+sr)/2;
        if(i <= sm) update(i, c, sl, sm, 2*si+1, st);
        else update(i, c, sm+1, sr, 2*si+2, st);
        st[si] = merge(st[2*si+1], st[2*si+2]);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int q = queryCharacters.size();
        vector<Node> st(4*n);
        vector<int> ans(q);
        build(0, n-1, 0, st, s);
        for(int i = 0; i < q; i++) {
            update(queryIndices[i], queryCharacters[i], 0, n-1, 0, st);
            ans[i] = st[0].val;
        }
        return ans;
    }
};