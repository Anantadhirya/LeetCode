struct Node {
    int cnt[5];
    int prod = 1;
};

class Solution {
public:
    int k;
    vector<Node> st;
    Node merge(Node a, Node b) {
        for(int i = 0; i < k; i++) {
            a.cnt[(i*a.prod)%k] += b.cnt[i];
        }
        a.prod = (a.prod * b.prod) % k;
        return a;
    }
    void build(int sl, int sr, int si, vector<int> &nums) {
        if(sl == sr) {
            for(int i = 0; i < k; i++) st[si].cnt[i] = 0;
            st[si].cnt[nums[sl]%k] = 1;
            st[si].prod = nums[sl]%k;
            return;
        }
        int sm = (sl+sr)/2;
        build(sl, sm, 2*si+1, nums);
        build(sm+1, sr, 2*si+2, nums);
        st[si] = merge(st[2*si+1], st[2*si+2]);
    }
    void update(int i, int val, int sl, int sr, int si) {
        if(sl == sr) {
            for(int i = 0; i < k; i++) st[si].cnt[i] = 0;
            st[si].cnt[val%k] = 1;
            st[si].prod = val%k;
            return;
        }
        int sm = (sl+sr)/2;
        if(i <= sm) update(i, val, sl, sm, 2*si+1);
        else update(i, val, sm+1, sr, 2*si+2);
        st[si] = merge(st[2*si+1], st[2*si+2]);
    }
    Node query(int l, int r, int sl, int sr, int si) {
        if(sr < l || r < l) return {};
        if(l <= sl && sr <= r) return st[si];
        int sm = (sl+sr)/2;
        return merge(query(l, r, sl, sm, 2*si+1), query(l, r, sm+1, sr, 2*si+2));
    }
    vector<int> resultArray(vector<int>& nums, int _k, vector<vector<int>>& queries) {
        int n = nums.size();
        k = _k;
        st.resize(4*n);
        vector<int> ans;
        
        build(0, n-1, 0, nums);
        for(auto &i: queries) {
            update(i[0], i[1], 0, n-1, 0);
            ans.push_back(query(i[2], n-1, 0, n-1, 0).cnt[i[3]]);
        }
        return ans;
    }
};