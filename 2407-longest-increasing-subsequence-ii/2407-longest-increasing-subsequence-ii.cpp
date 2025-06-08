const auto init = []() { ios_base::sync_with_stdio(false); cin.tie(0); return nullptr; }();

class Solution {
public:
    int query(int l, int r, int sl, int sr, int si, vector<int> &st) {
        if(sr < l || r < sl) return 0;
        if(l <= sl && sr <= r) return st[si];
        int sm = (sl+sr)/2;
        return max(query(l, r, sl, sm, 2*si+1, st), query(l, r, sm+1, sr, 2*si+2, st));
    }
    void update(int idx, int val, int sl, int sr, int si, vector<int> &st) {
        st[si] = max(st[si], val);
        if(sl == sr) return;
        int sm = (sl+sr)/2;
        if(idx <= sm) update(idx, val, sl, sm, 2*si+1, st);
        else update(idx, val, sm+1, sr, 2*si+2, st);
    }
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> st(4*mx, 0);
        int ans = 0, dp;
        for(const int &i: nums) {
            dp = query(max(1, i-k), i-1, 1, mx, 0, st) + 1;
            ans = max(ans, dp);
            update(i, dp, 1, mx, 0, st);
        }
        return ans;
    }
};